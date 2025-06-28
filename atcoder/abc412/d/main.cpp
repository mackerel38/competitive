#include "template"
#include "graphtemplate"
#include "UnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vpi e;
    rep(i, n) rep(j, n-i-1) e.pb({i, i+j+1});
    int b = 0;
    rep(i, m) {
        int x, y; cin >> x >> y; x--, y--;
        if (y < x) swap(x, y);
        int k = 0;
        while (e[k].fi!=x || e[k].se!=y) k++;
        b |= 1<<k;
    }
    int ans = inf;
    int cnt = -1+(1<<n), M = 1<<e.size();
    while (cnt < M) {
        vi cnts(8);
        for (int i=cnt; i!=0; i&=i-1) {
            int k = __builtin_ctz(i);
            cnts[e[k].fi]++; cnts[e[k].se]++;
        }
        bool flag = true;
        rep(i, n) if (cnts[i] != 2) { flag = false; break; }
        if (flag) ans = min(ans, __builtin_popcount(b^cnt));
        int r = cnt&(-cnt), u = cnt+r;
        cnt = u+((u^cnt)/r)/4;
    }
    cout << ans << nl;
}
