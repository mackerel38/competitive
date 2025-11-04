#include "autodp/template.hpp"
#include "autodp/matrix.hpp"
#include "autodp/string/naive.hpp"

template <class VTYPE>
VTYPE solvedp(const string& s) { vector<vector<VTYPE>>matP_ume={{1,1,1},{2,4,8},{4,8,18}};
        vector<vector<vector<VTYPE>>>mats_ume={{{1,0,0},{0,0,1},{-2,-3,4}},{{0,1,0},{-3,0,2},{-6,-2,5}}};
        int R = sz(matP_ume);
        int K = sz(mats_ume)
        ;Matrix<VTYPE> matP(matP_ume);
        vector<Matrix<VTYPE>> mats(K);
        rep(k, K) mats[k] = Matrix<VTYPE>(mats_ume[k]);
        Matrix<VTYPE> mat(R);
        repe(c, s) mat = mat * mats[c - '0'];
        mat = mat * matP;
        return mat[0][0];
}

int main() {
    long long n; cin >> n;
    cout << solvedp<mint>(bitset<60>(n).to_string()) << '\n';
}