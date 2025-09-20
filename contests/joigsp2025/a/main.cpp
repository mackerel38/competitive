#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    uniq(a);
    int cnt = 1;
    rep1(i, n-1) {
        if (a[i-1]+1 == a[i]) cnt++;
        if (cnt == k) {
            Yes;
            return;
        } else {
            cnt = 1;
        }
    }
    No;
}