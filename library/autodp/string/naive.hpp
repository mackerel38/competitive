#include <bits/stdc++.h>
using namespace std;

#include "atcoder/modint"
using namespace atcoder;
using mint = modint998244353;
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>; using pim = pair<int, mint>;
inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }

// 文字の種類数
#define N 10
// len の上限値
#define LEN_LIM -1

mint naive(const string& s) {
    long long l=0, r=0, v=0;
    for (auto& c : s) {
        int x = c - '0';
        l<<=1; l+=x&1; x>>=1;
        r<<=1; r+=x&1; x>>=1;
        v<<=1; v+=x&1; x>>=1;
    }
    mint re=0;
    for (ll i=l; i<=r; i++) for (ll j=i; j<=r; j++) {
        ll s = 0;
        for (ll k=i; k<=j; k++) s ^= k;
        if (s == v) re++;
    }
    return re;
}
