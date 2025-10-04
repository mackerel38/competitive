#include "template"
#include "prime"
#include "atcoder/modint"
using namespace atcoder;
vi p;
ll M;
vvll a;
int P;
void pre() {
    cin >> M;
    modint::set_mod(M);
    p = enumprimes(5000);
    P = p.size();
    vvll A(5001, vll(P));
    for (int i=2; i<=5000; i++) {
        int I = i;
        rep(j, P) {
            while (I%p[j] == 0) {
                I /= p[j];
                A[i][j]++;
            }
        }
    }
    for (int i=3; i<=5000; i++) rep(j, P) A[i][j] += A[i-1][j];
    a = A;
}

int main() {
    IO();
    int T=1;
    cin >> T;
    pre();
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll c(n); cin >> c;
    ll s = Sum(c);
    vll k = a[s];
    rep(i, n) {
        rep(j, P) k[j] -= a[c[i]][j];
    }
    modint ans = 1;
    rep(i, P) {
        modint x = p[i];
        ans *= x.pow(k[i]);
    }
    cout << ans.val() << nl;
}