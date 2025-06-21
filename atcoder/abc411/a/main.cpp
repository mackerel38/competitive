#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    int n; cin >> n;
    YN(n <= s.size());
}