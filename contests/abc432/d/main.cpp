#include "template"
#include "atcoder/segtree"
using namespace atcoder;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

pll op(pll x, pll y) { return {x.fi+y.fi, x.se+y.se}; }
pll e() { return {0, 0}; }

void solve() {
}