#include "template"
#include "lazysegtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
struct S {
    int M;
    int cnt;
};
S op(S a, S b) {
    if (a.M == b.M) return {a.M, a.cnt + b.cnt};
    elif (a.M < b.M) return b;
    else return a;
}
S e() { return S{-inf, 0}; }
using F = int;
S mapping(F f, S s) { return S{s.M + f, s.cnt}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
void solve() {
    int n, q; cin >> n >> q;
    lazysegtree<S, op, F, mapping, composition> seg(n);
    vec<set<pair<ll, set<ll>>>> a(n);
}