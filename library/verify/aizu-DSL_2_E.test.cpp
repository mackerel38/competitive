#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
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
        int x; cin >> x;
        if (x == 0) {
            int l, r, y; cin >> l >> r >> y; l--;
            s.imos(l, r, y);
        } else {
            int y; cin >> y;
            cout << s.sum(y) << nl;
        }
    }
}