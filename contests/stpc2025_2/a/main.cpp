#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    if (false) {
        if (n == 1) {
            Yes;
        } elif (n == 2 && k == 1) {
            Yes;
            cout << 1 << sp << 2 << nl;
        } elif (n == 3 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
        } elif (n == 4 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
        } elif (n == 5 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 1 << sp << 3 << nl;
            cout << 1 << sp << 4 << nl;
            cout << 1 << sp << 5 << nl;
        } elif (n == 5 && k == 3) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
            cout << 4 << sp << 5 << nl;
        } else {
            No;
        }
        return;
    }
    if (n == 1) {
        Yes;
        return;
    }
    if (n == 2 && k == 1) {
        Yes;
        cout << 1 << sp << 2 << nl;
        return;
    }
    if (k == 1) {
        No;
        return;
    }
    if (n == k) {
        if (n < 7) {
            No;
        } else {
            Yes;
            cout << 1 << sp << 4 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
            rep(i, n-4) {
                cout << i+4 << sp << i+5 << nl;
            }
        }
        return;
    }
    if (k == 2) {
        Yes;
        rep1(i, n-1) {
            cout << 1 << sp << i+1 << nl;
        }
        return;
    }
    if (n == 4 && k == 3) {
        No;
        return;
    }
    if (k == 3) {
        if (n%2 == 0) {
            Yes;
            cout << 1 << sp << n/2+1 << nl;
            rep(t, 2) {
                int T = t * (n/2);
                cout << T+1 << sp << T+2 << nl;
                rep(i, n/2-2) {
                    cout << T+2 << sp << T+i+3 << nl;
                }
            }
        } else {
            Yes;
            rep(i, n/2) {
                cout << 1 << sp << 2*i+2 << nl;
                cout << 2*i+2 << sp << 2*i+3 << nl;
            }
        }
        return;
    }
    Yes;
    rep1(i, k-1) {
        cout << i << sp << i+1 << nl;
    }
    rep1(i, n-k) {
        cout << 2 << sp << i+k << nl;
    }
}