#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "template"
#include "splaytree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    splaytree<int> t, T;
    rep(i, n) if (s[i] == '1') { t.insert(i); T.insert(-i); }
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == 0) { t.insert(y); T.insert(-y); }
        elif (x == 1) { t.erase(y); T.erase(-y); }
        elif (x == 2) { cout << t.contains(y) << nl;}
        elif (x == 3) {
            auto z = t.lower_bound(y);
            cout << (z==nullptr ? -1 : z->v) << nl;
        } else {
            auto z = T.lower_bound(-y);
            cout << (z==nullptr ? -1 : -(z->v)) << nl;
        }
    }
}