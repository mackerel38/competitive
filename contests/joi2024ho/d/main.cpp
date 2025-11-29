#include "template"
#include "lazysegtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n); cin >> a >> b;
    range(i, a) i--;
    range(i, b) i--;
    lazysegtree<int,[](int x,int y){return min(x, y);},[](){return inf;},int,[](int x,int y){return x;},[](int x,int y){return x;},[](){return inf;}> seg(n);
    lazysegtree<int,[](int x,int y){return max(x, y);},[](){return -1;},int,[](int x,int y){return x;},[](int x,int y){return x;},[](){return -1;}> seg2(n);
    rep(i, n) {
        int l = b[i], r = a[i]; l--;
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--;
    }
}