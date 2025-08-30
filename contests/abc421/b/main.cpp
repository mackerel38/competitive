#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vll dp(10); cin >> dp[0] >> dp[1];
    for (int i=2; i<10; i++) {
        ll x = dp[i-1] + dp[i-2];
        str s;
        bool flag = false;
        while (x) {
            char c = '0' + (x % 10);
            if (c != '0' || flag) {
                flag = true;
                s += c;
            }
            x /= 10;
        }
        ll y = 0;
        range(j, s) {
            y *= 10;
            y += j - '0';
        }
        dp[i] = y;
        debug(y);
    }
    cout << dp[9] << nl;
}