#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n); cin >> a;
    Sort(a);
    cout << a;
}