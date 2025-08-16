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
    graph<int,false,false> g(n);
    g.read(n-1);
    vi sd(n, inf), fd(n, inf); fd[0]=0; sd[n-1]=0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(e, g[x]) {
            if(chmin(fd[e.to], fd[e.from]+1)) {
                q.push(e.to);
            }
        }
    }
    q.push(n-1);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(e, g[x]) {
            if(chmin(sd[e.to], sd[e.from]+1)) {
                q.push(e.to);
            }
        }
    }
    int cnt=0;
    rep(i, n) if(fd[i]<=sd[i]) cnt++;
    cout << (n < 2 * cnt ? "Fennec" : "Snuke") << nl;
}