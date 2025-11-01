#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    str s; cin >> s;
    ll ans = 0;
    vi A(n+1), B(n+1);
    rep(i, n) {
        A[i+1] = A[i] + (s[i]=='a');
        B[i+1] = B[i] + (s[i]=='b');
    }
    rep(i, n) {
        int l = lower_bound(all(A), A[i]+a) - A.begin();
        int r = lower_bound(all(B), B[i]+b) - B.begin() - 1;
        ans += max(0, r - l + 1);
    }
    cout << ans << nl;
}