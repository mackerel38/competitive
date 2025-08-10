#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "template"
#include "convolution"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m); cin >> a; cin >> b;
    vi c = convolution(a, b);
    cout << c;
}