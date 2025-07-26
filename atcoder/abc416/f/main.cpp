#include "template"
#include "graphtemplate"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vll a; cin >> a;
    graph<int, false, false> g(n);
    g.read(n-1);
}