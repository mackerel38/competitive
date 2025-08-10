#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "template"
#include "xorconvolution"
#include "modint"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<mint> a(1<<n), b(1<<n);
    cin >> a >> b;
    vec<mint> c = xorconvolution(a, b);
    cout << c;
}