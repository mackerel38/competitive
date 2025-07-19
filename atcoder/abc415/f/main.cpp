#include "template"
#include "segtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

struct S {
    int len, p, t, M;
    char lc, rc;
};
S op(S a,S b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    S c;
    c.len = a.len + b.len;
    c.lc = a.lc;
    c.rc = b.rc;
    c.p = a.p + ((a.p==a.len && a.rc==b.lc) ? b.p : 0);
    c.t = b.t + ((b.t==b.len && a.rc==b.lc) ? a.t : 0);
    c.M = max({a.M, b.M, ((a.rc==b.lc) ? (a.t + b.p) : 0)});
    return c;
}
S e() { return {0, 0, 0, 0, 0, 0}; }

void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    vector<S> a(n);
    rep(i, n) a[i] = {1, 1, 1, 1, s[i], s[i]};
    segtree<S, op, e> seg(a);
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int y; char c; cin >> y >> c; y--;
            seg.set(y, {1, 1, 1, 1, c, c});
        } else {
            int l, r; cin >> l >> r; l--;
            cout << seg.prod(l, r).M << nl;
        }
    }
}
