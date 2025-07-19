#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    int n = s.size();
    int flag = 0;
    rep(i, n) {
        if (s[i] == '#') {
            cout << i + 1;
            if (flag) {
                cout << nl;
            } else {
                cout << ',';
            }
            flag = 1 - flag;
        }
    }
}