#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vi a(3); cin >> a;
    uniq(a);
    YN(a.size()<3);
}