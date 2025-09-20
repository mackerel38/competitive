#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n); cin >> a;
    graph<int, true, false> g(n+1);
    rep(i, n) {
        g.add_edge(a[i].fi, i+1);
        g.add_edge(a[i].se, i+1);
    }
    vi visited(n+1); visited[0] = 1;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(i, g[x]) {
            if (0 == visited[i.to]) {
                visited[i.to] = 1;
                q.push(i.to);
            }
        }
    }
    cout << Sum(visited)-1 << nl;
}