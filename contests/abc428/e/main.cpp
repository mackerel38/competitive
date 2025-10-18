#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vvi g(n);
    rep(i, n-1) {
        int x, y; cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vi dist(n, inf); dist[0] = 0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(i, g[x]) if (chmin(dist[i], dist[x]+1)) q.push(i);
    }
    int d = Max(dist);
    int s = -1;
    per(i, n) {
        if (dist[i] == d) {
            s = i;
            break;
        }
    }
    vi dist2(n, inf); dist2[s] = 0;
    q.push(s);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(i, g[x]) if (chmin(dist2[i], dist2[x]+1)) q.push(i);
    }
    int D = Max(dist2);
    int t = -1;
    per(i, n) {
        if (dist2[i] == D) {
            t = i;
            break;
        }
    }
    vi dist3(n, inf); dist3[t] = 0;
    q.push(t);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(i, g[x]) if (chmin(dist3[i], dist3[x]+1)) q.push(i);
    }
    s++; t++;
    rep(i, n) {
        if (dist2[i] == dist3[i]) {
            cout << max(s, t) << nl;
        } elif (dist2[i] < dist3[i]) {
            cout << t << nl;
        } else {
            cout << s << nl;
        }
    }
}