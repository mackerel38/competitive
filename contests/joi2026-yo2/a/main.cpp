#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    Sort(a);
    vi b = a;
    uniq(b);
    int m = b.size();
    vec<pair<pi, int>> ans;
    rep(i, m) {
        int x = lower_bound(all(a), b[i]-1) - a.begin();
        int y = n - x;
        ans.pb({{abs(x-y), y}, b[i]});
    }
    Sort(ans);
    cout << ans[0].se << nl;
}