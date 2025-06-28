#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    if (n == 2) {
        cout << (2*a[0] >= a[1] ? 2 : -1) << nl;
        return;
    }
    vi b(n-2); rep(i, n-2) b[i] = a[i+1];
    Sort(b);
    int m = n - 2;
    vi dp(m, inf); // dp[i] := 長さiで達成できる最大値
    dp[0] = 2*a[0];
    rep(i, m) {
        int l=0, r=n-1;
        while (1 < r - l) {
            int mid = (l + r) / 2;
            if (dp[mid] <= b[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        dp[r] = b[i] * 2;
    }
    cout << dp;
    rep(i, m) {
        if (a.back() < dp[i]) {
            cout << i + 3 << nl;
            return;
        }
    }
    cout << -1 << nl;
}
