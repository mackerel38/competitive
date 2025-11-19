#include "template"
#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    mint a, b, c;
    {
        int A, B, C; cin >> A >> B >> C;
        a = A; b = B; c = C;
    }
    mint A = b * c, B = c * a, C = a * b;
    cout << ((-A+B+C)/(A-B)).val() << sp << ((-A+B+C)/(A-C)).val() << nl;
}