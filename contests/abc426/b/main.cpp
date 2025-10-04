#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    map<char, int> cnt;
    range(i, s) cnt[i]++;
    range(i, cnt) {
        if (i.se == 1) {
            cout << i.fi << nl;
        }
    }
}