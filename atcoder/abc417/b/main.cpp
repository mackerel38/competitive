#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    vi b(m); cin >> b;
    Sort(b);
    vi c;
    int i=0, j=0;
    while (i<n && j<m) {
        if (a[i] == b[j]) {
            j++;
        } elif (a[i] < b[j]) {
            c.pb(a[i]);
        } else {
            i--;
            j++;
        }
        i++;
    }
    while (i < n) {
        c.pb(a[i]);
        i++;
    }
    cout << c;
}