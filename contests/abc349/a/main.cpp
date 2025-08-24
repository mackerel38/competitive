#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int x, y; cin >> x >> y;
    cout << ((x-1+y)%12)+1 << nl;
}