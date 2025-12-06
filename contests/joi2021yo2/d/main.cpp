#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vll a(n), b(n); cin >> a >> b;
    ll l = a.back(), r = a.back()+Sum(b);
    while (1 < r - l) {
        ll mid = (l + r) / 2;
        ll cnt = 0, x=0;
        per(i, n) {
            if (b[i] <= x) x -= b[i];
            else {
                ll m = (mid-a[i]+b[i]-x-1) / (mid-a[i]);
                cnt += m;
                x += (mid - a[i]) * m - b[i];
            }
        }
        if (cnt <= k) r = mid;
        else l = mid;
    }
    cout << r << nl;
}