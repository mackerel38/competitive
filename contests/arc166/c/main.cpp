#include "template"
#include "modint"

vec<mint> fib(2000001);
vec<mint> fibp(1000001);

int main() {
    fib[0] = 1; fib[1] = 2;
    for (int i=2; i<=2000000; i++) fib[i] = fib[i-1] + fib[i-2];
    fibp[1] = fib[1];
    for (int i=2; i<=1000000; i++) fibp[i] = fibp[i-1] * fib[2*i-1];
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ll h, w; cin >> h >> w;
    if (w < h) swap(h, w);
    cout << fibp[h] * fibp[h] * fib[2*h].pow(w - h) << nl;
}