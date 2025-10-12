#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int o = 0;
    range(i, a) o |= i;
    int x = 0;
    range(i, a) x ^= i;
    cout << (o^x ? "Alice" : "Bob") << nl;
}