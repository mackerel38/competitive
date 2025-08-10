#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    Sort(a);
    ll A = Sum(a);
    vll ans(min(1000000LL, A));
    ans[0] = 1;
    int l = -1;
    rep1(i, min(1000000LL, A)-1) {
        while(l<n && (l == -1 || a[l] < i)) l++;
        ans[i] = ans[i-1] + (n-l);
    }
    range(i, ans) if (A < i) i = -1;
    debug(ans);
    while (q--) {
        int x; cin >> x;
        cout << ans[x-1] << nl;
    }
}