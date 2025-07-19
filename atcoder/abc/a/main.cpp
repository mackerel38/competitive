#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

int modpow(int x, int n, int m) {
    int re = 1;
    int k = x;
    while (n) {
        if (n & 1) re = (1LL * re * k) % m;
        k = (1LL * k * k) % m;
        n >>= 1;
    }
    return re;
}

void solve() {
    int n = 10000;
    rep1(i, n) {
        vi mp;
        rep(j, n) {
            mp.pb(modpow(j, 2, i));
        }
        uniq(mp);
        if(mp.size() == 2) {
            cout << i << sp;
        }
    }
}