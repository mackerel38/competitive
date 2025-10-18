#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    int c = 0, m = 0;
    stack<char> s;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            char y; cin >> y;
            if (y == '(') {
                c++;
            } else {
                c--;
            }
            s.push(y);
            if (c < 0) m++;
        } else {
            if (c < 0) m--;
            if (s.top() == '(') {
                c--;
            } else {
                c++;
            }
            s.pop();
        }
        YN(c == 0 && m == 0);
    }
}