#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpll a(n); cin >> a;
    Sort(a);
    vec<pi> b;
    rep(i, n) rep(j, i) b.pb({i, j});
    sort(all(b), [&](const pi x,const pi y) {
        return (a[x.fi].fi-a[x.se].fi)*(a[y.fi].se-a[y.se].se)<(a[y.fi].fi-a[y.se].fi)*(a[x.fi].se-a[x.se].se);
    });
    ll ans = 0;
    int i = 0;
    ll cnt = 0;
    while (i < b.size()) {
        int j = i;
        while (j != b.size() && (a[b[i].fi].fi-a[b[i].se].fi)*(a[b[j].fi].se-a[b[j].se].se)==(a[b[j].fi].fi-a[b[j].se].fi)*(a[b[i].fi].se-a[b[i].se].se)) j++;
        ans += (j-i)*(j-i-1)/2;
        vll c;
        for (int I=i; I<j; I++) {
            c.pb((a[b[I].fi].fi-a[b[I].se].fi)*(a[b[I].fi].fi-a[b[I].se].fi)+(a[b[I].fi].se-a[b[I].se].se)*(a[b[I].fi].se-a[b[I].se].se));
        }
        Sort(c);
        debug(c);
        int I = i;
        while (I < j) {
            int J = I;
            while (J != j && c[I-i] == c[J-i]) J++;
            cnt += (J-I)*(J-I-1)/2;
            I = J;
        }
        i = j;
    }
    debug(cnt);
    cout << ans - cnt / 2 << nl;
}