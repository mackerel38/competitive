#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class VTYPE>
VTYPE solvedp(const string &s)
{
	constexpr int DIM = 6;
	constexpr int COL = 4;
	VTYPE matAs[COL][DIM][DIM] = {{{1,0,0,0,0,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,-3,0,4,0,0},{0,-2,0,3,2,-1},{0,-5,0,5,0,1}},{{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,-3,0,3,1,0},{0,0,0,0,1,0},{0,-5,0,4,1,1}},{{0,1,0,0,0,0},{0,0,0,0,0,1},{0,0,1,0,1,0},{0,-3,0,3,0,1},{0,-2,0,2,2,0},{0,-5,0,3,0,3}},{{0,0,1,0,0,0},{0,0,0,-1,1,1},{0,0,1,0,0,0},{0,-3,0,2,1,1},{0,0,0,-1,1,1},{0,-5,0,2,1,3}}};
	VTYPE vecQ[DIM] = {0,1,1,2,2,4};
	array<VTYPE, DIM> dp;
	dp[0] = 1;
	for (int i = int(1), i_end = int(DIM - 1); i <= i_end; ++i)
		dp[i] = 0;
	auto apply = [&](const array<VTYPE, DIM> &x, int col)
	{
		array<VTYPE, DIM> z;
		for (int j = 0, j_len = int(DIM); j < j_len; ++j)
		{
			z[j] = 0;
			for (int i = 0, i_len = int(DIM); i < i_len; ++i)
				z[j] += x[i] * matAs[col][i][j];
		}
		return z;
	};
	for (const auto &c : (s))
	{
		dp = apply(dp, c - '0');
	}
	VTYPE res = 0;
	for (int i = 0, i_len = int(DIM); i < i_len; ++i)
		res += vecQ[i] * dp[i];
	return res;
}