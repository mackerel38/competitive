#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "template"
#include "prime"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        auto y = factorize(x);
        cout << y;
    }
}