#include "template"
#include "segtree"
#include "modint"
using mint = modint<998244353>;
#include "Nyaan/rbst/treap.hpp"

vector<mint> po;
struct T {
    int l;
    mint v;
};
using E = char;
T f(T a, T b) { return T{a.l+b.l, a.v*po[b.l]+b.v}; }
T g(T a, E b) { return a; }
E h(E a, E b) {return E{}; }
T ts(T a) { return T{}; }
using Treap = LazyReversibleTreap<T, E, f, g, h, ts>;
Treap treap;

struct S {
    int B;
    Treap::Ptr root;
};
S op(S a, S b) {
    if (a.root == nullptr && a.B == 0) return b;
    if (b.root == nullptr && b.B == 0) return a;
    S re;
    int A = treap.size(a.root);
    debug(A);
    int d = min(b.B, A);
    Treap::Ptr left, del;
    if (a.root != nullptr) {
        auto p = treap.split(a.root, A - d);
        left = p.fi; del = p.se;
    }
    else left = del = nullptr;
    delete del;
    re.root = treap.merge(left, b.root);
    re.B = a.B + b.B - d;
    return re;
}
S e() { return S{0, nullptr};}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    po.assign(n+10, mint(0)); po[0] = mint(1);
    rep1(i, po.size()-1) po[i] = 10 * po[i-1];
    vector<S> a(n);
    rep(i, n) {
        if (s[i] == 'B') a[i] = S{1, nullptr};
        else a[i] = S{0, treap.build(vec<T>{T{1, s[i]-'0'}})};
    }
    segtree<S, op, e> seg(a);
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y; char c; cin >> y >> c; y--;
            if (c == 'B') seg.set(y, S{1, nullptr});
            else seg.set(y, S{0, treap.build(vec<T>{T{1, c-'0'}})});
        } else {
            int l, r; cin >> l >> r; l--;
            S re = seg.prod(l, r);
            int len = treap.size(re.root);
            if (len == 0) {
                cout << -1 << nl;
            } else {
                cout << re.root->sum.v << nl;
            }
        }
    }
}

// teap のサイズがnより大きくなる...