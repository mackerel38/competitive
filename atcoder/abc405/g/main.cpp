#include "template"
#include "modint"
#include "Mo"
#include "sqrttree"

int main() { IO();
    buildfac(300000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a; rep(i, n) a[i]--;
    Mo mo(n);
    vi queries(q), ans(q);
    rep(i, q) {
        int x, y, z; cin >> x >> y >> z;
        queries[i] = z-1;
        mo.add(x-1, y);
    }
    sqrttree<int,[](int a,int b){return a+b;},[](){return 0;},int,[](int a,int b){return a+b;},[](int a,int b){return a+b;}> seg1(n);
    auto op = [](ll a, ll b) -> ll {return a * b % mod;};
    auto e = []() -> ll {return 1;};
    sqrttree<ll,op,e,ll,op,op> seg2(n);
    vll inve(n+1); rep1(i, n) inve[i] = mint(i).inv().val;
    auto add = [&](int x) {
        seg1.apply(a[x], 1);
        seg2.apply(a[x], seg1[a[x]]);
    };
    auto erase = [&](int x) {
        seg2.apply(a[x], inve[seg1[a[x]]]);
        seg1.apply(a[x], -1);
    };
    auto out = [&](int x) {
        ans[x] = (fac[seg1.prod(0, queries[x])] / seg2.prod(0, queries[x])).val;
    };
    mo.build(add, erase, out);
    range(i, ans) cout << i << nl;
}

