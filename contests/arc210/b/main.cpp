#include "template"
#include "atcoder/segtree"
using namespace atcoder;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vll a(n), b(m); cin >> a >> b;
    vec<pair<ll, pll>> query(q); cin >> query;
    vll s;
    range(i, a) s.pb(i);
    range(i, b) s.pb(i);
    range(i, query) s.pb(i.se.se);
    uniq(s);
    int S = s.size();
    vll c(S+1);
    vll A(n), B(m), Q(q);
    rep(i, n) A[i] = lower_bound(all(s), a[i])-s.begin();
    rep(i, m) B[i] = lower_bound(all(s), b[i])-s.begin();
    rep(i, q) Q[i] = lower_bound(all(s), query[i].se.se)-s.begin();
    range(i, A) c[i+1]++;
    range(i, B) c[i+1]++;
    range(i, Q) c[i+1]++;
    rep(i, S) c[i+1] += c[i];
    vll C(S);
    vpll v(n+m+q);
    rep(i, n) v[c[A[i]]+(C[A[i]]++)] = {1, a[i]};
    rep(i, m) v[c[B[i]]+(C[B[i]]++)] = {1, b[i]};
    segtree<pll,[](pll x,pll y){return pll{x.fi+y.fi,x.se+y.se};},[](){return pll{0, 0};}> seg(v);
    rep(i, q) {
        auto [x, p] = query[i]; auto [y, z] = p; y--;
        if (x == 1) {
            int t = lower_bound(all(s), a[y]) - s.begin();
            int T = lower_bound(all(s), z) - s.begin();
            seg.set(c[t]+(--C[t]), {0, 0});
            seg.set(c[T]+(C[T]++), {1, z});
            a[y] = z;
        } else {
            int t = lower_bound(all(s), b[y]) - s.begin();
            int T = lower_bound(all(s), z) - s.begin();
            seg.set(c[t]+(--C[t]), {0, 0});
            seg.set(c[T]+(C[T]++), {1, z});
            b[y] = z;
        }
        cout << (seg.prod(0, seg.max_right(0, [&n](pll x){return x.fi<=n/2;})).se) + (seg.prod(seg.min_left(n+m+q, [&n](pll x){return x.fi<=n/2;}), n+m+q).se) << nl;
        assert(n == (seg.prod(0, seg.max_right(0, [&n](pll x){return x.fi<=n/2;})).fi) + (seg.prod(seg.min_left(n+m+q, [&n](pll x){return x.fi<=n/2;}), n+m+q).fi));
    }
}