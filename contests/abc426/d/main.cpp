#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    int ans = inf;
    0; {
        int ans2 = n;
        range(i, s) if (i == '0') ans2 += 1;
        int k = 1, t=0;
        char c = s[0];
        rep1(i, n-1) {
            if (s[i] == c) k++;
            else {
                if (c == '0') chmax(t, k);
                k = 1;
                c = s[i];
            }
        }
        if (c == '0') chmax(t, k);
        ans2 -= 2*t;
        chmin(ans, ans2);
    }
    1; {
        int ans2 = n;
        range(i, s) if (i == '1') ans2 += 1;
        int k = 1, t=0;
        char c = s[0];
        rep1(i, n-1) {
            if (s[i] == c) k++;
            else {
                if (c == '1') chmax(t, k);
                k = 1;
                c = s[i];
            }
        }
        if (c == '1') chmax(t, k);
        ans2 -= 2*t;
        chmin(ans, ans2);
    }
    cout << ans << nl;
}