#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<str> s(n); cin >> s;
    int x; cin >> x;
    str t; cin >> t;
    YN(t == s[x-1]);
}