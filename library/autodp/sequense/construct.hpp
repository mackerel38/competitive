#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "autodp/matrix.hpp"
#include "atcoder/modint"
using namespace atcoder;

template <class CTYPE, auto NAIVE>
void embed_coefs(int K=2, int len_max = 1001001001, int LB_max = 1001001001) {
	vector<string> ss{""};
	int idx = 0;
	vector<pair<int, int>> piv_prv;
	for(int len = int(0), len_end = int(1001001001); len <= len_end; ++len) {
		int L = ((int)(ss).size()); int LB = min(L, LB_max);
		Matrix<CTYPE> mat(L, LB);
		for(int i = 0, i_len = int(L); i < i_len; ++i) for(int j = 0, j_len = int(LB); j < j_len; ++j) mat[i][j] = NAIVE(ss[i] + ss[j]);
		auto piv = row_reduced_form(mat);
		if (len == len_max || (((int)(piv).size()) > 0 && ((int)(piv).size()) == ((int)(piv_prv).size()))) {
			int R = ((int)(piv).size());
			vector<int> is(R), js(R);
			for(int r = 0, r_len = int(R); r < r_len; ++r) tie(is[r], js[r]) = piv[r];
			sort((js).begin(), (js).end());
			Matrix<CTYPE> P(R, R);
			for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) P[i][j] = NAIVE(ss[is[i]] + ss[js[j]]);
			auto P_inv = inverse_matrix(P);
			vector<Matrix<CTYPE>> mats(K, Matrix<CTYPE>(R, R));
			for(int k = 0, k_len = int(K); k < k_len; ++k) {
				char c = '0' + k;
				for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) mats[k][i][j] = NAIVE(ss[is[i]] + c + ss[js[j]]);
				mats[k] = mats[k] * P_inv;
			}
			auto to_signed_string = [](CTYPE x) {
				int v = x.val();
				int mod = CTYPE::mod();
				if (2 * v > mod) v -= mod;
				return to_string(v);
			};
			ofstream ofs("/home/mackerel38/competitive/library/autodp/sequense/generated.hpp");
            string eb = "";
            eb += "#pragma once\n";
            eb += "#include <bits/stdc++.h>\n";
            eb += "using namespace std;\n";
            eb += "\n";
            eb += "template <class VTYPE>\n";
            eb += "VTYPE solvedp(const vector<VTYPE>& wgt) {\n";
			eb += "\tconstexpr int DIM = ";
			eb += to_string(R);
			eb += ";\n";
			eb += "\tconstexpr int COL = ";
			eb += to_string(K);
			eb += ";\n";
			eb += "\tVTYPE matAs[COL][DIM][DIM] = {";		
			for(int k = 0, k_len = int(K); k < k_len; ++k) {
				eb += "{";
				for(int i = 0, i_len = int(R); i < i_len; ++i) {
					eb += "{";
					for(int j = 0, j_len = int(R); j < j_len; ++j) eb += to_signed_string(mats[k][i][j]) + ",";
					eb.pop_back();
					eb += "},";
				}
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n";
			eb += "\tVTYPE vecQ[DIM] = {";
			for(int i = 0, i_len = int(R); i < i_len; ++i) eb += to_signed_string(P[i][0]) + ",";
			eb.pop_back();
			eb += "};\n";
            eb += "\tarray<VTYPE, DIM> dp;\n";
			eb += "\tdp[0] = 1;\n";
            eb += "\tfor (int i=1; i<DIM; i++) dp[i] = 0;\n";
			eb += "\tarray<VTYPE, COL> fact_inv;\n";
			eb += "\tfact_inv[0] = 1;\n";
			eb += "\tfor (int i=1; i<COL; i++) fact_inv[i] = fact_inv[i-1] / i;\n";
			eb += "\tarray<VTYPE, COL> fixed;\n";
			eb += "\tfor (int i=0; i<COL; i++) fixed[i] = ((COL-1-i) & 1 ? -1 : 1) * fact_inv[i] * fact_inv[COL-1-i];\n";
			eb += "\tarray<VTYPE, COL> acc_l, acc_r;\n";
			eb += "\tauto lagrange_interpolation = [&](const array<VTYPE, COL>& y, VTYPE c) {\n";
			eb += "\t\tacc_l[0] = 1;\n";
			eb += "\t\tfor (int i=1; i<COL; i++) acc_l[i] = acc_l[i - 1] * (c - (i - 1));\n";
			eb += "\t\tacc_r[COL - 1] = 1;\n";
			eb += "\t\tfor (int i=COL-2; 0<=i; i--) acc_r[i] = (c - (i + 1)) * acc_r[i + 1];\n";
			eb += "\t\tVTYPE res = 0;\n";
			eb += "\t\tfor (int i=0; i<COL; i++) res += y[i] * acc_l[i] * acc_r[i] * fixed[i];\n";
			eb += "\t\treturn res;\n";
			eb += "\t};\n";
            eb += "\tauto apply = [&](const array<VTYPE, DIM>& x, VTYPE w) {\n";
            eb += "\t\tarray<VTYPE, DIM> z;\n";
			eb += "\t\tfor (int j=0; j<DIM; j++) {\n";
			eb += "\t\t\tz[j] = 0;\n";
			eb += "\t\t\tfor (int i=0; i<DIM; i++) {\n";
			eb += "\t\t\t\tarray<VTYPE, COL> ys;\n";
			eb += "\t\t\t\tfor (int c=0; c<COL; c++) ys[c] = matAs[c][i][j];\n";
			eb += "\t\t\t\tz[j] += x[i] * lagrange_interpolation(ys, w);\n";
			eb += "\t\t\t}\n";
			eb += "\t\t}\n";
            eb += "\t\treturn z;\n";
            eb += "\t};\n";
            eb += "\tfor (const auto& w : wgt) dp = apply(dp, w);\n";
            eb += "\tVTYPE res = 0;\n";
            eb += "\tfor (int i=0; i<DIM; i++) res += vecQ[i] * dp[i];\n";
            eb += "\treturn res;\n";
            eb += "}\n";
			ofs << eb << endl;
			exit(0);
		}
		int nidx = ((int)(ss).size());
		for(int i = int(idx), i_end = int(nidx - 1); i <= i_end; ++i) for(int k = 0, k_len = int(K); k < k_len; ++k) {
			ss.push_back(ss[i]);
			ss.back().push_back('0' + k);
		}
		idx = nidx;
		piv_prv = move(piv);
	}
}
