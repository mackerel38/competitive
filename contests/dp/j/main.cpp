#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vec<vec<vec<ld>>> dp(n+1, vec<vec<ld>>(n+1, vec<ld>(n+1))); dp[0][0][0] = 0;
    // (n){i, j, k} = (n-i-j-k){i, j, k} + (i){i-1, j, k}, ...
    rep(i, n+1) rep(j, n+1) rep(k, n+1) {
        if (0 < i) dp[i][j][k] += (dp[i-1][j][k]+1) * (1.*i / (i+j+k));
        if (0 < j) dp[i][j][k] += (dp[i+1][j-1][k]+1) * (1.*j / (i+j+k));
        if (0 < k) dp[i][j][k] += (dp[i][j+1][k-1]+1) * (1.*k / (i+j+k));
    }
    vi x(3);
    range(i, a) x[i-1]++;
    cout << dp[x[0]][x[1]][x[2]] << nl; 
}