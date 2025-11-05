#include <bits/stdc++.h>
using namespace std;

#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>; using pim = pair<int, mint>;
inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }

// 文字の種類数
#define N 26
// len の上限値
#define LEN_LIM 2
#define LB_LIM -1

mint naive(const string& s) {
    int n = s.size();
    vector<string> a;
    for (int i=1; i<(1<<n); i++) if (i&(i<<1) == 0) {
        string t;
        for (int j=0; j<n; j++) if ((i>>j)&1) {
            t += s[j];
        }
        a.push_back(t);
    } 
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a.size();
}
