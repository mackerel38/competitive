#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "wordsizetree"
#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    str st; cin >> st;
    rep(i, n) if (st[i] == '1') a[i] = 1;
    wordsizetree s(a);
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == 0) {
            s.insert(y);
        } elif (x == 1) {
            s.erase(y);
        } elif (x == 2) {
            cout << s.count(y) << nl;
        } elif (x == 3) {
            int z = s.minright(y);
            cout << (z<n ? z : -1) << nl;
        } else {
            int z = s.maxleft(y);
            cout << (0<=z ? z : -1) << nl;
        }
    }
}