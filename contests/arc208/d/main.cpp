#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi y(n); cin >> y;
    range(i, y) i--;
    vvi ans(n, vi(n));
    rep(i, n) ans[i][y[i]] = ans[y[i]][i] = 1;
    vec<set<int>> r(n), c(n);
    rep(i, n) rep(j, n) {
        if (ans[i][j] == 1) {
            if (r[i].count(1)) {
                No;
                return;
            } else {
                r[i].insert(1);
            }
            if (c[j].count(1)) {
                No;
                return;
            } else {
                c[j].insert(1);
            }
        }
    }
    Yes;
    vi mexr(n, 1), mexc(n, 1);
    rep(i, n) rep(j, n) {
        if (ans[i][j] == 1) {
            mexr[i] = 2;
            mexc[j] = 2;
        }
    }
    rep(i, n) rep(j, n) {
        if (ans[i][j] == 0) {
            int x = ans[i][j] = max(mexr[i], mexc[j]);
            r[i].insert(x);
            c[j].insert(x);
            while (r[i].count(mexr[i]) == 0) {
                mexr[i]++;
            }
            while (c[j].count(mexc[j]) == 0) {
                mexc[j]++;
            }
        }
    }
    if (max(Max(mexr), Max(mexc)) > n) {
        No;
        return;
    }
    cout << ans;
}