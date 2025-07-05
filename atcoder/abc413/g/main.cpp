#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, n; cin >> h >> w >> n;
    vpi a(n); cin >> a;
    rep(i, n) { a[i].fi--; a[i].se--; }
    Sort(a);
    vvi b(h);
    range(i, a) b[i.fi].pb(i.se);
    queue<pi> q; q.push({0, 0});
    rep(i, h) {
        if (b[i].empty()) {
            while (!q.empty()) q.pop();
            q.push({0, w-1});
            continue;
        }
        int c = -1;
        queue<pi> nq;
        range(j, b[i]) {
            cout << i << sp << j << nl;
            if (c + 1 == j) {
                c = j;
                continue;
            }
            while (!q.empty() && q.front().se < c) q.pop();
            if (q.empty()) break;
            if (q.front().fi < j) {
                nq.push({c+1, j-1});
                continue;
            }
            c = j;
        }
        while (!q.empty()) q.pop();
        while (!nq.empty()) {
            q.push(nq.front());
            cout << nq.front() << sp;
            nq.pop();
        }
        cout << nl;
        if (q.empty()) break;
    }
    if (!q.empty()) {
        pi x;
        while (!q.empty()) {x = q.front(); q.pop();}
        if (x.se == w-1) {
            Yes;
            return;
        }
    }
    No;
}