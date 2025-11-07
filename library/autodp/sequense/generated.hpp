#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class VTYPE>
VTYPE solvedp(const vector<VTYPE>& wgt) {
	constexpr int DIM = 4;
	constexpr int COL = 2;
	VTYPE matAs[COL][DIM][DIM] = {{{0,1,0,0},{1,1,0,0},{2,0,2,-1},{2,2,1,-1}},{{0,0,1,0},{0,0,0,1},{1,-1,2,0},{1,0,2,0}}};
	VTYPE vecQ[DIM] = {0,0,1,0};
	array<VTYPE, DIM> dp;
	dp[0] = 1;
	for (int i=1; i<DIM; i++) dp[i] = 0;
	array<VTYPE, COL> fact_inv;
	fact_inv[0] = 1;
	for (int i=1; i<COL; i++) fact_inv[i] = fact_inv[i-1] / i;
	array<VTYPE, COL> fixed;
	for (int i=0; i<COL; i++) fixed[i] = ((COL-1-i) & 1 ? -1 : 1) * fact_inv[i] * fact_inv[COL-1-i];
	array<VTYPE, COL> acc_l, acc_r;
	auto lagrange_interpolation = [&](const array<VTYPE, COL>& y, VTYPE c) {
		acc_l[0] = 1;
		for (int i=1; i<COL; i++) acc_l[i] = acc_l[i - 1] * (c - (i - 1));
		acc_r[COL - 1] = 1;
		for (int i=COL-2; 0<=i; i--) acc_r[i] = (c - (i + 1)) * acc_r[i + 1];
		VTYPE res = 0;
		for (int i=0; i<COL; i++) res += y[i] * acc_l[i] * acc_r[i] * fixed[i];
		return res;
	};
	auto apply = [&](const array<VTYPE, DIM>& x, VTYPE w) {
		array<VTYPE, DIM> z;
		for (int j=0; j<DIM; j++) {
			z[j] = 0;
			for (int i=0; i<DIM; i++) {
				array<VTYPE, COL> ys;
				for (int c=0; c<COL; c++) ys[c] = matAs[c][i][j];
				z[j] += x[i] * lagrange_interpolation(ys, w);
			}
		}
		return z;
	};
	for (const auto& w : wgt) dp = apply(dp, w);
	VTYPE res = 0;
	for (int i=0; i<DIM; i++) res += vecQ[i] * dp[i];
	return res;
}

