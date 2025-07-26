#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, l, r; cin >> n >> l >> r;
    str s; cin >> s;
    for (int i=l-1; i<r; i++) {
        if (s[i] == 'x') {
            No;
            return;
        }
    }
    Yes;
}