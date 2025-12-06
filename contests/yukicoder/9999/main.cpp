#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    vi t = {-1, 0, 1, 0, -1, 0, -1, -1};
    int m = 0;
    rep(i, 3) { m<<=1; m|=s[i]-'A'; }
    m = t[m];
    cout << (n!=1 ? "BB" : "B");
    loop(i, 2, n) {
        if (m < 0) cout << s[i];
        else {
            cout << 'A';
            if (s[i] == 'A'+m) m--;
        }
    }
    cout << nl;
}