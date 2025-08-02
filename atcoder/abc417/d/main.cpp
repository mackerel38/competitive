#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<pair<int, pi>> a(n); cin >> a;
    vvi dp(n+1, vi(501)); // a[i][j] := iこめの直前でjだったときの答え
    rep1(i, 500) dp[n][i] = i;
    vll s(n+1); per(i, n) s[i] = s[i+1] + a[i].se.se;
    per(i, n) {
        rep(j, 501) {
            if (j <= a[i].first) {
                if (j+a[i].se.fi<=500) {
                    dp[i][j] = dp[i+1][j+a[i].se.fi];
                } elif (500 < j+a[i].se.fi-s[i+1]) {
                    dp[i][j] = j + a[i].se.fi - s[i+1];
                } else {
                    int l=i+1, r=n+1;
                    while (1 < r - l) {
                        int m = (l + r) / 2;
                        if (500 < j + a[i].se.fi - s[i+1]+s[m]) {
                            l = m;
                        } else {
                            r = m;
                        }
                    }
                    dp[i][j] = dp[r][j+a[i].se.fi-s[i+1]+s[r]];
                }
            } else {
                dp[i][j] = dp[i+1][max(0, j-a[i].se.se)];
            }
        }
    }
    debug(dp);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (500 < x) {
            if (x - s[0] > 500) {
                cout << x - s[0] << nl;
                continue;
            }
            int l = 0, r = n + 1;
            while (1 < r - l) {
                int m = (l + r) / 2;
                if (500 < x - s[0] + s[m]) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << dp[r][x-s[0]+s[r]] << nl;
        } else {
            cout << dp[0][x] << nl;
        }
    }
}