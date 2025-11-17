#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class VTYPE>
VTYPE solvedp(const vector<VTYPE>& wgt) {
	constexpr int DIM = 11;
	constexpr int COL = 2;
	VTYPE matAs[COL][DIM][DIM] = {{{0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0},{0,-100,100,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,1},{0,-111100,111100,100,-100,-90,100,-10,91,-100,10},{0,0,0,0,0,0,0,0,0,0,0},{0,299473316,-299473316,0,0,-299473305,0,299473305,-1,0,1},{0,399196731,-399196731,299473406,-299473406,-469174937,299473406,169701531,90,-100,10}},{{0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0},{0,-100,100,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,-1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,-1,1,1},{0,-111100,111100,100,-100,-90,100,-10,90,-99,10},{0,1,-1,-1,1,1,-1,0,-1,1,0},{0,299473317,-299473317,-1,1,-299473304,-1,299473305,-2,1,1},{0,399196732,-399196732,299473405,-299473405,-469174936,299473405,169701531,89,-99,10}}};
	VTYPE vecQ[DIM] = {0,0,100,0,1100,0,1010,110100,0,10,101100};
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

