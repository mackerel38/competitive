#include "template"
#include "autodp/stringdp"
using mint = modint1000000007;
mint naive(const str& s) {
    auto tohash = [](const string& s) -> mint {
        mint re = 0;
        range(c, s) {
            re *= 3;
            re += c - '0';
        }
        return re;
    };
    set<int> ans;
    queue<str> q; q.push(s);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        rep(i, x.size()-1) if (x[i] != x[i+1]) {
            str t="";
            rep(j, i-1) t += x[j];
            t += '0' + (3 - ((x[i]-'0') + (x[i+1]-'0')));
            loop(j, i+2, x.size()) t += x[j];
            mint y = tohash(t);
            if (ans.find(y.val()) == ans.end()) {
                ans.insert(y.val());
                q.push(t);
            }
        }
    }
    return ans.size();
}
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    embed_coefs<mint, naive>(3, 10);
    /*
    int n; str s; cin >> n >> s;
    str t=""; rep(i, n) t += '0' + (s[i] - 'A');
    cout << solvedp<mint>(t).val() << nl;
    */
}