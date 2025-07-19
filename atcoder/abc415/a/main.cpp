#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int x; cin >> x;
    range(i, a) {
        if (i == x) {
            Yes;
            return;
        }
    }
    No;
}