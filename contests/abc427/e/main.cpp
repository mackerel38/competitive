#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    int Tx, Ty;
    vec<pi> a;
    rep(i, h) rep(j, w) {
        if (s[i][j] == 'T') {
            Tx = i;
            Ty = j;
        } elif (s[i][j] == '#') {
            a.pb({i, j});
        }
    }
    vec<str> st(h, str(w, '0'));
    range(i, a) st[i.fi][i.se] = '1';
    queue<pair<vec<str>, int>> q;
    set<vec<str>> visited;
    q.push({st, 0});
    visited.insert(st);
    while (!q.empty()) {
        auto [x, d] = q.front(); q.pop();
        bool flag  = true;
        range(i, x) range(j, i) if (j == '1') flag = false;
        if (flag) {
            cout << d << nl;
            return;
        }
        rep(dd, 4) {
            vec<str> y(h, str(w, '0'));
            bool flag2 = false;
            rep(i, h) rep(j, w) if (x[i][j] == '1') {
                int I = i + dxy[dd], J = j + dxy[dd+1];
                if (I == Tx && J == Ty) flag2 = true;
                if (ismid(0, I, h) && ismid(0, J, w)) y[I][J] = '1';
            }
            if (!flag2) {
                if (visited.insert(y).second) q.push({y, d+1});
            }
        }
    }
    cout << -1 << nl;
}