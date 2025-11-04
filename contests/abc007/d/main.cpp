#include "autodp/template.hpp"
#include "autodp/matrix.hpp"
#include "autodp/string/naive.hpp"
template <class VTYPE>
VTYPE solve(const string& s) {
        vector<vector<VTYPE>>matP_ume={{0,0,0,1},{0,2,2,3},{1,9,10,13},{1,18,18,19}};
        vector<vector<vector<VTYPE>>>mats_ume={{{1,0,0,0},{-1,0,0,2},{-4,-4,1,8},{23,-40,0,18}},{{0,1,0,0},{-2,1,0,2},{-1,-8,1,9},{22,-39,0,18}},{{-1,2,0,0},{-3,2,0,2},{2,-12,1,10},{21,-38,0,18}},{{-2,3,0,0},{-4,3,0,2},{5,-16,1,11},{20,-37,0,18}},{{0,0,1,0},{-2,0,1,2},{8,-20,1,12},{22,-40,1,18}},{{0,0,0,1},{-2,0,0,3},{11,-24,1,13},{22,-40,0,19}},{{-1,1,0,1},{-3,1,0,3},{14,-28,1,14},{21,-39,0,19}},{{-2,2,0,1},{-4,2,0,3},{17,-32,1,15},{20,-38,0,19}},{{-3,3,0,1},{-5,3,0,3},{20,-36,1,16},{19,-37,0,19}},{{-1,0,1,1},{-3,0,1,3},{23,-40,1,17},{21,-40,1,19}}};
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
    ll l, r; cin >> l >> r; l--;
    string s = to_string(l), t = to_string(r);
    cout << solve<ll>(t)-solve<ll>(s) << '\n';
}