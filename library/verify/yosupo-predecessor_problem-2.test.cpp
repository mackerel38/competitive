#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "template"
#include "segtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    vi a(n); rep(i, n) a[i] = s[i] - '0';
    segtree<int,[](int x,int y){return x+y;},[](){return 0;}> seg(a);
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == 0) seg.set(y, 1);
        elif (x == 1) seg.set(y, 0);
        elif (x ==2) cout << seg[y] << nl;
        elif (x == 3) {
            int z = seg.max_right(y, [](int x){return x<1;});
            cout << (z==n ? -1 : z) << nl;
        } else {
            cout << seg.min_left(y+1, [](int x){return x<1;})-1 << nl;
        }
    }
}