#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class VTYPE>
vector<VTYPE> solvedp(const vector<vector<int>>& g, int r) {
	vector<vector<VTYPE>>matA={{-500000001,-499999998},{500000003,500000002}};
	vector<vector<vector<VTYPE>>>tsrM={{{0,-2},{-2,-6}},{{1,3},{3,7}}};
	vector<VTYPE>vecQ={2,4};
	int R = ((int)(matA).size());
	int n = ((int)(g).size());
	vector<vector<VTYPE>> dp(n, vector<VTYPE>(R));
	for(int s = 0, s_len = int(n); s < s_len; ++s) dp[s][0] = 1;
	auto apply = [&](const vector<VTYPE>& x) {
		vector<VTYPE> z(R);
		for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[i] += matA[i][j] * x[j];
		return z;
	};
	auto merge = [&](const vector<VTYPE>& x, const vector<VTYPE>& y) {
		vector<VTYPE> z(R);
		for(int k = 0, k_len = int(R); k < k_len; ++k) for(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[k] += x[i] * tsrM[k][i][j] * y[j];
		return z;
	};
	function<void(int, int)> dfs = [&](int s, int p) {
		bool is_leaf = true;
		for(const auto& t : (g[s])) {
			if (t == p) continue;
			dfs(t, s);
			if (is_leaf) {
				dp[s] = dp[t];
			}
			else {
				dp[s] = merge(dp[s], dp[t]);
			}
			is_leaf = false;
		}
		if (!is_leaf) dp[s] = apply(dp[s]);
	};
	dfs(r, -1);
	vector<VTYPE> res(n);
	for(int s = 0, s_len = int(n); s < s_len; ++s) {
		for(int j = 0, j_len = int(R); j < j_len; ++j) res[s] += vecQ[j] * dp[s][j];
	}
	return res;
}

