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
    int N = 2 * n;
    graph<int, false, false> g(2*n);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--; x<<=1; y<<=1;y++;
        g.add_edge(x, y);
    }
    vec<char> visited(N);
    vi ord(n, -1); vi ans,  idx(N);
    int j = 0;
    rep(i, N) if (visited[i] == false) {
        stack<int> s; s.push(i);
        visited[i] = true;
        int cnt = 0;
        while (!s.empty()) {
            int x = s.top(); s.pop();
            if (ord[x/2] != j) {
                ord[x/2] = j;
                cnt++;
            }
            idx[x] = j;
            range(e, g[x]) if (visited[e.to] == false) {
                visited[e.to] = true;
                s.push(e.to);
            }
        }
        ans.pb(cnt);
        j++;
    }
    rep(i, n) cout << n - ans[idx[2*i]] << nl;
}