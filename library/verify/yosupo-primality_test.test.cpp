#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

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
        YN(isprime(x));
    }
}