#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s = "0";
    { str t; cin >> t; s += t; }
    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (x == (1 << n) - 1) {
            Yes;
            return;
        }
        rep(i, n) if (!bit(x, i)) {
            int y = x | (1 << i);
            if (s[y] == '0') {
                s[y] = '1';
                q.push(y);
            }
        }
    }
    No;
}