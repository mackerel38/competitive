#include "template"
#include "modint"

int main() { IO();
    int T=1;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vvi a(n, vi(6)); cin >> a;
    vpi b;
    rep(i, n) rep(j, 6) b.pb({a[i][j], i});
    b.pb({0, -1});
    Sort(b);
    mint ans = 0;
    int pre = 0, cnt0 = n;
    mint cur = 1;
    vi cnts(n);
    range(i, b) {
        auto [x, y] = i;
        if (pre < x) {
            if (0 < cnt0) ans += x - pre;
            else ans += (x - pre) * (1 - cur);
        }
        if (y != -1) {
            int pcnt = cnts[y]++;
            if (pcnt == 0) cnt0--;
            if (cnt0 == 0) {
                if (pcnt == 0) {
                    cur = 1;
                    rep(j, n) {
                        cur *= cnts[j];
                        cur /= 6;
                    }
                } else {
                    cur /= pcnt;
                    cur *= pcnt + 1;
                }
            }
        }
        pre = x;
    }
    cout << ans << nl;
}