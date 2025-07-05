#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<str> s(n); cin >> s;
    set<str> st;
    rep(i, n) rep(j, n) if (i != j) {
        str t = s[i] + s[j];
        st.insert(t);
    }
    cout << st.size() << nl;
}