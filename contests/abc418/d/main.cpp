#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    ll ans = 0;
    int zero = 0;
    queue<int> odd, even;even.push(0);
    rep(i, n) {
        if (s[i] == '0') zero++;
        if (zero%2 == 0) {
            even.push(i);
        } else {
            odd.push(i);
        }
    }
    ll e = even.size();
    ll o = odd.size();
    cout << e*(e-1)/2+o*(o-1)/2 << nl;
}