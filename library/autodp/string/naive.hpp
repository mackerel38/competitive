#include <bits/stdc++.h>
using namespace std;

#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>; using pim = pair<int, mint>;
inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }

#define N 2

mint naive(const string& s) {
    int n = 0;
    for (auto& c : s) n = n * 2 + (c - '0');
    vector<pair<int, int>> uv;
    for (int a=0; a<=n; a++) for (int b=0; b<=n-a; b++) {
        int u = a ^ b;
        int v = a + b;
        if (u <= n) uv.emplace_back(u, v);
    }
    sort(uv.begin(), uv.end());
    uv.erase(unique(uv.begin(), uv.end()), uv.end());
    return uv.size();
}
