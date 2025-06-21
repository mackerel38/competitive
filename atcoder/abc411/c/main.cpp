#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n+2);
    int ans = 0;
    rep(i, q) {
        int x; cin >> x;
        if (!a[x]) {
            if (a[x-1] && a[x+1]) {
                ans--;
            } elif (a[x-1] || a[x+1]) {
                ;
            } else {
                ans++;
            }
            a[x] = 1;
        } else {
            if (a[x-1] && a[x+1]) {
                ans++;
            } elif (a[x-1] || a[x+1]) {
                ;
            } else {
                ans--;
            }
            a[x] = 0;
        }
        cout << ans << nl;
    }
}