#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "template"
#include "suffixarray"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    vi sa = suffixarray(s);
    rep1(i, s.size()) cout << sa[i] << sp;
    cout << nl;
}