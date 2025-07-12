#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str ans = "";
    ll cnt = 0;
    rep(i, n) {
        char c; int x; cin >> c >> x;
        cnt += x;
        if (cnt > 100) {
            O("Too Long");
            return;
        }
        ans += str(x, c);
    }
    O(ans);
}