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
    vi cnt(n+1);
    range(i, a) if (i != -1) cnt[i]++;
    if (Max(cnt) < 2) {
        Yes;
        rep(i, n) if (a[i] == -1) {
            rep1(j, n) {
                if (cnt[j] == 0) {
                    cnt[j]++;
                    a[i] = j;
                    break;
                }
            }
        }
        cout << a;
    } else {
        No;
    }
}