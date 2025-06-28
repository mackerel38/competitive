#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s, t; cin >> s >> t;
    rep1(i, s.size()-1) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            bool flag = false;
            range(j, t) if (s[i-1] == j) flag = true;
            if (!flag) {
                No;
                return;
            }
        }
    }
    Yes;
}