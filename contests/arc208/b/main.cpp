#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; ll k; cin >> n >> k;
    ll po = 1; rep(i, n-1) { po *= 2; chmin(po, k+1); }
    po--;
    vll ans;
    ans.pb(1+(k+po-1)/po);
    if (po == 0) ans[0] = k + 1;
    rep1(i, n-1) {
        ll pre = ans.back() - 1;
        ll x = min(k, pre);
        ans.pb(pre + x + 1);
        k -= x;
    }
    cout << ans;
}