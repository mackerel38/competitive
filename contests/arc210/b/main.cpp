#include "template"
#include "bipq"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    ll N = n / 2;
    vll a(n), b(m); cin >> a >> b;
    bipq<ll> left, mid, right;
    range(i, a) left.push(a[i]);
    range(i, b) right.push(b[i]);
    while (N < left.size()) {
        
    }
}