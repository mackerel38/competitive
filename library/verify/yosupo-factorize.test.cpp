#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "template"
#include "prime"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ll n; cin >> n;
    vll ans;
    factorize(n, ans);
    Sort(ans);
    cout << ans.size() << sp << ans;
}