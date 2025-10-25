#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, false, false> g(n); g.read(m);
    vi visited(n);
    vpi d(n, {inf, -1}), d2(n, {inf, -1});
    str s; cin >> s;
    queue<pair<int, pi>> q;
    rep(i, n) {
        if (s[i] == 'S') {
            q.push({0, {i, i}});
            d[i] = {0, i};
            visited[i]++;
        }
    }
    while (!q.empty()) {
        auto [dist, p] = q.front(); q.pop();
        auto [x, from] = p;
        range(e, g[x]) {
            int y = e.to;
            if (d[y].se == from) continue;
            if (d2[y].se == from) continue;
            if (visited[y] == 0) {
                d[y] = {dist + 1, from};
                visited[y]++;
                q.push({dist + 1, {y, from}});
            }
            elif (visited[y] == 1) {
                d2[y] = {dist + 1, from};
                visited[y]++;
                q.push({dist + 1, {y, from}});
            }
        }
    }
    debug(d);
    debug(d2);
    rep(i, n) if (s[i] == 'D') cout << d[i].fi + d2[i].fi << nl;
}