#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vvll a(3, vll(3));
    cin >> a;
    vvi b(3, vi(3));
    auto f = [&](auto&& self, int t) -> bool {
        if (t == 9) {
            range(i, b) range(j, i) if (j == 0) j = 1;
            ll T=0, A=0;
            rep(i, 3) rep(j, 3) {
                if (b[i][j] == 1) T += a[i][j];
                else A += a[i][j];
            }
            if (A < T) return true;
            else return false;
        }
        bool re = false;
        rep(i, 3) rep(j, 3) if (b[i][j] == 0) {
            if (t%2 == 0) {
                b[i][j] = 1;
            } else {
                b[i][j] = 2;
            }
            if (b[i][0]==b[i][1] && b[i][1]==b[i][2]) re = true;
            if (b[0][j]==b[1][j] && b[1][j]==b[2][j]) re = true;
            if (re == false && self(self, t+1) == false) re = true;
            b[i][j] = 0;
            if(re) return re;
        }
        return false;
    };
    if (f(f, 0) == false) cout << "Takahashi" << nl;
    else cout << "Aoki" << nl;
}