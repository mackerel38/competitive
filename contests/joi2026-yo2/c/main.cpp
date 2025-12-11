#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve_wa() {
    int n; cin >> n;
    str s; cin >> s;
    per(i, n-2) {
        if (s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I') {
            s[i] = 'O';
            s[i+1] = 'I';
            s[i+2] = 'J';
        }
    }
    cout << s << nl;
}
/*
  JJJOIOI
  JJOIJOI
  JOIJOIJ
  OIJOIJJ
  OIOIJJJ
  JJJOIOIOI
  OIが離れないので、Jを後ろに
*/
void solve() {
    int n; cin >> n;
    str s; cin >> s;
    vi a;
    rep(i, n) {
        if (i < n-1 && s[i] == 'O' && s[i+1] == 'I') {
            a.pb(1);
            i++;
        } elif (s[i] == 'J') {
            a.pb(0);
        } elif (s[i] == 'O') {
            a.pb(2);
        } elif (s[i] == 'I') {
            a.pb(3);
        }
    }
    int m = a.size();
    int cnt = 0, cnt2 = 0;
    rep(i, m) {
        if (a[i] == 0) cnt++;
        elif (a[i] != 1) {
            rep(j, cnt2) cout << "OI";
            cnt2 = 0;
            rep(j, cnt) cout << 'J';
            cnt = 0;
            if (a[i] == 2) {
                cout << 'O';
            } else {
                cout << 'I';
            }
        } else {
            cnt2++;
        }
    }
    while (cnt2--) cout << "OI";
    while (cnt--) cout << 'J';
    cout << nl;
}