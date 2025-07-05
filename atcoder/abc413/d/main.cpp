#include "template"

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    map<ll, int> cnt;
    range(i, a) cnt[i]++;
    uniq(a);
    if ((int)a.size() < n) {
        if (a.size() == 1) {
            Yes; return;
        } else if (a.size()==2 && n%2==0) {
            ll x = a[0], y = a[1];
            if (abs(x) > abs(y)) swap(x, y);
            if (abs(x) == abs(y) && cnt[x] == n/2 && cnt[y] == n/2) {
                Yes;
                return;
            }
        }
        No;
        return;
    }
    sort(a.begin(), a.end(), [](ll a, ll b) {return abs(a) < abs(b);});
    rep1(i, n-1) {
        if (a[i] * a[0] != a[i-1] * a[1]) {
            No;
            return;
        }
    }
    Yes;
}
