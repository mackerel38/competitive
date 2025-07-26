#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    bool flag = true;
    range(i, s) {
        if (i == '#') flag = true;
        if (i == '.' && flag) {
            flag = false;
            cout << 'o';
        } else {
            cout << i;
        }
    }
    cout << nl;
}