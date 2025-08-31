#include "template"
#include "syntax"
#define MOD 1'000'000'007
#undef sp
#define rr x.r*y.r
#define rs x.r*y.s
#define rp x.r*y.p
#define sr x.s*y.r
#define ss x.s*y.s
#define sp x.s*y.p
#define pr x.p*y.r
#define ps x.p*y.s
#define pp x.p*y.p
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

struct rsp {
    ll r, s, p;
};

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    vec<str> op = {"+-", "*"};
    str t = syntax(s, op);
    auto w = [](rsp x, rsp y) -> rsp { return rsp{(rr+rs+sr)%MOD, (ss+sp+ps)%MOD, (pp+pr+rp)%MOD}; };
    auto l = [](rsp x, rsp y) -> rsp { return rsp{(rr+rp+pr)%MOD, (ss+sr+rs)%MOD, (pp+ps+sp)%MOD}; };
    auto d = [](rsp x, rsp y) -> rsp { return rsp{(rr+sp+ps)%MOD, (ss+rp+pr)%MOD, (pp+rs+sr)%MOD}; };
    stack<rsp> st;
    range(i, t) {
        rsp x;
        if (i == 'R') x = {1, 0, 0};
        elif (i == 'S') x = {0, 1, 0};
        elif (i == 'P') x = {0, 0, 1};
        elif (i == '?') x = {1, 1, 1};
        elif (i == '+') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = w(y, z);
        } elif (i == '-') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = l(y, z);
        } elif (i == '*') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = d(y, z);
        }
        st.push(x);
    }
    rsp ans = st.top(); st.pop();
    char tar; cin >> tar;
    if (tar == 'R') cout << ans.r << nl;
    if (tar == 'S') cout << ans.s << nl;
    if (tar == 'P') cout << ans.p << nl;
}