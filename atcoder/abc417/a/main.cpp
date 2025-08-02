#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    str s; cin >> s;
    for (int i=a; i<n-b; i++) {
        cout << s[i];
    }
    cout << nl;
}