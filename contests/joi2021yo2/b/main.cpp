#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    int N = 1; rep(i, n) N *= 3;
    vi dp(N, inf);
    queue<int> qu;
    rep(i, n+1) {
        rep(j, n+1) {
            int k = n - i - j;
            if (0 <= k) {
                int x = 0;
                rep(J, j) x = x * 3 + 1;
                rep(K, k) x = x * 3 + 2;
                dp[x] = 0;
                qu.push(x);
            }
        }
    }
    while (!qu.empty()) {
        int x = qu.front(); qu.pop();
        int X = x;
        vi v; rep(i, n) { v.pb(X%3); X/=3; }
        rep(i, n-1) {
            reverse(v.begin()+i, v.end());
            int y=0; per(j, n) y = y * 3 + v[j];
            if (chmin(dp[y], dp[x]+1)) qu.push(y);
            reverse(v.begin()+i, v.end());
        }
    }
    while (q--) {
        str s; cin >> s;
        int x = 0;
        range(i, s) x = x * 3 + i - 'A';
        cout << dp[x] << nl;
    }
}