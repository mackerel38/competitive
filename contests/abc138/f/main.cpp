#include "autodp/template.hpp"
#include "autodp/matrix.hpp"
#include "autodp/string/naive.hpp"
template <class VTYPE>
VTYPE solve(const string& s) {
        vector<vector<VTYPE>>matP_ume={{0,0,0,1,1,0},{1,2,2,4,4,4},{1,1,0,3,1,0},{2,5,5,7,7,13},{2,4,2,6,4,4},{4,9,9,13,13,23}};
        vector<vector<vector<VTYPE>>>mats_ume={{{1,0,0,0,0,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,-3,0,4,0,0},{0,-2,0,3,2,-1},{0,-5,0,5,0,1}},{{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,-3,0,3,1,0},{0,0,0,0,1,0},{0,-5,0,4,1,1}},{{0,1,0,0,0,0},{0,0,0,0,0,1},{0,0,1,0,1,0},{0,-3,0,3,0,1},{0,-2,0,2,2,0},{0,-5,0,3,0,3}},{{0,0,1,0,0,0},{0,0,0,-1,1,1},{0,0,1,0,0,0},{0,-3,0,2,1,1},{0,0,0,-1,1,1},{0,-5,0,2,1,3}}};
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
    long long l, r; cin >> l >> r;
    string s;
    for (int i=60; 0<=i; i--) {
        s += '0' + (((l>>i)&1) + ((r>>i)&1)*2);
    }
    cout << solve<mint>(s) << '\n';
}