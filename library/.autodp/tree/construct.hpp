#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "autodp/matrix.hpp"
#include "atcoder/modint"
using namespace atcoder;

template <class CTYPE, auto NAIVE>
void embed_coefs() {
	vector<vector<int>> trees{ {0} };
	int idx = 0;
	vector<pair<int, int>> piv_prv;
	for(int lv = int(2), lv_end = int(1001001001); lv <= lv_end; ++lv) {
		int L = ((int)(trees).size());
		Matrix<CTYPE> mat(L, L);
		for(int i = 0, i_len = int(L); i < i_len; ++i) for(int j = 0, j_len = int(L); j < j_len; ++j) {
			vector<int> tree(trees[i]);
			int p0 = tree.back();
			tree.pop_back();
			int offset = ((int)(tree).size());
			for(const auto& p : (trees[j])) {
				int np = (p == 0 ? p0 : p + offset);
				tree.push_back(np);
			}
			mat[i][j] = NAIVE(tree);
		}
		auto piv = row_reduced_form(mat);
		if (lv > 2 && ((int)(piv).size()) == ((int)(piv_prv).size())) {
			int R = ((int)(piv).size());
			vector<int> is(R), js(R);
			for(int r = 0, r_len = int(R); r < r_len; ++r) tie(is[r], js[r]) = piv[r];
			sort((js).begin(), (js).end());
			Matrix<CTYPE> P(R, R);
			for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) {
				vector<int> tree(trees[is[i]]);
				int p0 = tree.back();
				tree.pop_back();
				int offset = ((int)(tree).size());
				for(const auto& p : (trees[js[j]])) {
					int np = (p == 0 ? p0 : p + offset);
					tree.push_back(np);
				}
				P[i][j] = NAIVE(tree);
			}
			auto P_inv = inverse_matrix(P);
			Matrix<CTYPE> apply(R, R);
			for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) {
				vector<int> tree(trees[is[i]]);
				int offset = ((int)(tree).size());
				for(const auto& p : (trees[js[j]])) {
					int np = p + offset;
					tree.push_back(np);
				}
				apply[i][j] = NAIVE(tree);
			}
			apply = P_inv * apply;
			vector<vector<vector<CTYPE>>> merge(R, vector<vector<CTYPE>>(R, vector<CTYPE>(R)));
			for(int j1 = 0, j1_len = int(R); j1 < j1_len; ++j1) for(int j2 = 0, j2_len = int(R); j2 < j2_len; ++j2) {
				for(int i = 0, i_len = int(R); i < i_len; ++i) {
					vector<int> tree(trees[is[i]]);
					int p0 = tree.back();
					tree.pop_back();
					int offset = ((int)(tree).size());
					for(const auto& p : (trees[js[j1]])) {
						int np = (p == 0 ? p0 : p + offset);
						tree.push_back(np);
					}
					offset = ((int)(tree).size());
					for(const auto& p : (trees[js[j2]])) {
						int np = (p == 0 ? p0 : p + offset);
						tree.push_back(np);
					}
					merge[j1][j2][i] = NAIVE(tree);
				}
				merge[j1][j2] = P_inv * merge[j1][j2];
			}
			auto to_signed_string = [](CTYPE x) {
				int v = x.val();
				int mod = CTYPE::mod();
				if (2 * v > mod) v -= mod;
				return to_string(v);
			};
            ofstream ofs("/home/mackerel38/competitive/library/autodp/tree/generated.hpp");
			string eb = "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class VTYPE>\nvector<VTYPE> solvedp(const vector<vector<int>>& g, int r) {\n\tvector<vector<VTYPE>>matA={";
			for(int i = 0, i_len = int(R); i < i_len; ++i) {
				eb += "{";
				for(int j = 0, j_len = int(R); j < j_len; ++j) eb += to_signed_string(apply[i][j]) + ",";
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n\tvector<vector<vector<VTYPE>>>tsrM={";
			for(int i = 0, i_len = int(R); i < i_len; ++i) {
				eb += "{";
				for(int j1 = 0, j1_len = int(R); j1 < j1_len; ++j1) {
					eb += "{";
					for(int j2 = 0, j2_len = int(R); j2 < j2_len; ++j2) eb += to_signed_string(merge[j1][j2][i]) + ",";
					eb.pop_back();
					eb += "},";
				}
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n\tvector<VTYPE>vecQ={";
			for(int j = 0, j_len = int(R); j < j_len; ++j) eb += to_signed_string(P[0][j]) + ",";
			eb.pop_back();
			eb += "};\n";
            eb += "\tint R = ((int)(matA).size());\n\tint n = ((int)(g).size());\n\tvector<vector<VTYPE>> dp(n, vector<VTYPE>(R));\n\tfor(int s = 0, s_len = int(n); s < s_len; ++s) dp[s][0] = 1;\n\tauto apply = [&](const vector<VTYPE>& x) {\n\t\tvector<VTYPE> z(R);\n\t\tfor(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[i] += matA[i][j] * x[j];\n\t\treturn z;\n\t};\n\tauto merge = [&](const vector<VTYPE>& x, const vector<VTYPE>& y) {\n\t\tvector<VTYPE> z(R);\n\t\tfor(int k = 0, k_len = int(R); k < k_len; ++k) for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[k] += x[i] * tsrM[k][i][j] * y[j];\n\t\treturn z;\n\t};\n\tfunction<void(int, int)> dfs = [&](int s, int p) {\n\t\tbool is_leaf = true;\n\t\tfor(const auto& t : (g[s])) {\n\t\t\tif (t == p) continue;\n\t\t\tdfs(t, s);\n\t\t\tif (is_leaf) {\n\t\t\t\tdp[s] = dp[t];\n\t\t\t}\n\t\t\telse {\n\t\t\t\tdp[s] = merge(dp[s], dp[t]);\n\t\t\t}\n\t\t\tis_leaf = false;\n\t\t}\n\t\tif (!is_leaf) dp[s] = apply(dp[s]);\n\t};\n\tdfs(r, -1);\n\tvector<VTYPE> res(n);\n\tfor(int s = 0, s_len = int(n); s < s_len; ++s) {\n\t\tfor(int j = 0, j_len = int(R); j < j_len; ++j) res[s] += vecQ[j] * dp[s][j];\n\t}\n\treturn res;\n}\n";
			ofs << eb << endl;
			exit(0);
		}
		int nidx = ((int)(trees).size());
		for(int i = int(idx), i_end = int(nidx - 1); i <= i_end; ++i) for(int p = 0, p_len = int(lv); p < p_len; ++p) {
			trees.push_back(trees[i]);
			trees.back().push_back(p);
		}
		idx = nidx;
		piv_prv = move(piv);
	}
}
