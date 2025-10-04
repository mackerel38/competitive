#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str x, y; cin >> x >> y;
    if (x[0] == 'L') x[0] = 'Z';
    if (y[0] == 'L') y[0] = 'Z';
    YN(x[0] >= y[0]);
}