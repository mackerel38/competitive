#include <bits/stdc++.h>
using namespace std;

#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>; using pim = pair<int, mint>;
inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }

// 文字の種類数
#define N 10
// len の上限値
#define LEN_LIM -1
#define LB_LIM -1

mint naive(const string& s) {
    if (s.size() == 0) return 0;
    return stoll(s)%13 == 5;
}
