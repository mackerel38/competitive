#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vec<char> c(3); cin >> c;
    troS(c);
    cout << c[0] << c[1] << c[2] << nl;
}