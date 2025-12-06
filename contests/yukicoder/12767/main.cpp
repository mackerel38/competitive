#include "template"

using i128 = __int128_t;
i128 extgcd(i128 a, i128 b, i128& x, i128& y) {
    if (b == 0) {
        x = 1; y = 0;
        return max(a, -a);
    }
    i128 X=0, Y=0;
    i128 g = extgcd(b, a%b, X, Y);
    x = Y;
    y = X - (a / b) * Y;
}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    vll m, r;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y, z; cin >> y >> z;
        } elif (x == 2) {
            int y; cin >> y;
        } else {
            int y; cin >> y;
        }
    }
}