#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "template"
#include "BIT"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    BIT<int> s(n);
    while (q--) {
        int x, y, z; cin >> x >> y >> z; y--;
        if (x == 0) {
            s.add(y, z);
        } else {
            cout << s.sum(y, z) << nl;
        }
    }
}