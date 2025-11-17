#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    char m = '9';
    range(i, s) if (i != '0') chmin(m, i);
    bool flag = true;
    str ans = ""; ans += m;
    str t = "";
    range(i, s) {
        if (i == m) {
            if (flag) {
                flag = false;
            } else {
                t += i;
            }
        } else {
            t += i;
        }
    }
    Sort(t);
    cout << ans << t << nl;
}