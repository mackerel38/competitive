#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int a, b; cin >> a >> b;
    cout << a * 1000 / b + 1 << nl;
}