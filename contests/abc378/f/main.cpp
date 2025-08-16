#include "template"
#include "UnionFind"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    graph<int, false, false> g(n); g.read(n-1);
    UnionFind uf(n);
    auto es = g._edges;
    vi cnt(n);
    range(e, es) {
        if (g[e.to].size()==3 && g[e.from].size()==3) {
            uf.merge(e.to, e.from);
        } elif (g[e.to].size()==3 && g[e.from].size()==2) {
            cnt[e.to]++;
        } elif (g[e.to].size()==2 && g[e.from].size()==3) {
            cnt[e.from]++;
        }
    }
    auto groups = uf.groups();
    ll ans = 0;
    range(group, groups) {
        ll sum = 0;
        range(i, group) sum += cnt[i];
        ans += sum * (sum - 1) / 2;
    }
    cout << ans << nl;
}