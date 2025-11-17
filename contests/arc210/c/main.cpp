#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vi v = {4750, 4740, 4200, 5050, 1300, 4400, 3680, 138, 960, 7400};
    rep(i, 1<<10) {
        int sum = 0;
        rep(j, 10) {
            if (bit(i, j)) sum += v[j];
        }
        if (28670-35*100 < sum && sum <= 28670) {
            rep(j, 10) cout << bit(i, j) << sp;
            return;
        }
    }
}