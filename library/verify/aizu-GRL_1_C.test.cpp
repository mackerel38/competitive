#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"
#include "template"
#include "graphtemplate"
#include "warshallfloyd"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    vvll d = warshallfloyd(g);
    rep(i, n) if (d[i][i] < 0) {
        cout << "NEGATIVE CYCLE" << nl;
        return;
    }
    rep(i, n) {
        rep(j, n) {
            if (d[i][j] == numeric_limits<ll>::max()) {
                cout << "INF";
            } else {
                cout << d[i][j];
            }
            if (j != n - 1) cout << sp;
        }
        cout << nl;
    }
}