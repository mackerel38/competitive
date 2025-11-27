#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "template"
#include "prime"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vi primes = enumprimes(n);
    int m = primes.size();
    cout << m << sp << (m+a-1-b)/a << nl;
    for (int i=b; i<m; i+=a) cout << primes[i] << sp;
    cout << nl;
}