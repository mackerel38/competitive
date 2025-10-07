#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "template"
#include "convolution"
using mint = modint<998244353>;

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vec<mint> a(n), b(m); cin >> a; cin >> b;
    vec<mint> c = convolution(a, b);
    cout << c;
}