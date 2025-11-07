#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class VTYPE>
VTYPE solvedp(const vector<VTYPE>& wgt) {
	constexpr int DIM = 3;
	constexpr int COL = 10;
	VTYPE matAs[COL][DIM][DIM] = {{{2,0,0},{0,0,1},{0,-20,12}},{{0,1,0},{-4,2,1},{-8,-16,12}},{{-2,2,0},{-8,4,1},{-16,-12,12}},{{-4,3,0},{-12,6,1},{-24,-8,12}},{{-6,4,0},{-16,8,1},{-32,-4,12}},{{-8,5,0},{-20,10,1},{-40,0,12}},{{-10,6,0},{-24,12,1},{-48,4,12}},{{-12,7,0},{-28,14,1},{-56,8,12}},{{-14,8,0},{-32,16,1},{-64,12,12}},{{-16,9,0},{-36,18,1},{-72,16,12}}};
	VTYPE vecQ[DIM] = {0,1,11};
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

