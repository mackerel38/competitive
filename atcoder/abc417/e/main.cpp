#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, f, t; cin >> n >> m >> f >> t; f--; t--;
    vvi g(n);
    rep(i, m) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i, n) Sort(g[i]);
    vi ans;
    vi visited(n);
    int c = f;
    visited[c] = 1;
    ans.pb(c);
    while (c != t) {
        range(i, g[c]) {
            if (visited[i]) continue;
            queue<int> q; q.push(i);
            vi visited2(n);
            visited2[i] = 1;
            bool flag = false;
            while (!q.empty()) {
                if (flag) break;
                int x = q.front(); q.pop();
                if (x == t) flag = true;
                else {
                    range(y, g[x]) {
                        if (visited2[y]) continue;
                        if (visited[y]) continue;
                        visited2[y] = 1;
                        q.push(y);
                    }
                }
            }
            if (flag) {
                c = i;
                visited[c] = 1;
                ans.pb(c);
                break;
            }
        }
    }
    range(i, ans) cout << i+1 << sp;
    cout << nl;
}