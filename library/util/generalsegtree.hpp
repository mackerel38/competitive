#pragma once
#include "segtree"
#include <bits/stdc++.h>
using namespace std;
using rangesum_int=segtree<int,[](int a,int b)->int{return a+b;},[]()->int{return 0;}>;
using rangesum_ll=segtree<long long,[](long long a,long long b)->long long{return a+b;},[]()->long long{return 0LL;}>;
using rangemin_int=segtree<int,[](int a,int b)->int{return min(a,b);},[]()->int{return numeric_limits<int>::max();}>;
using rangemin_ll=segtree<long long,[](long long a,long long b)->long long{return min(a,b);},[]()->long long{return numeric_limits<long long>::max();}>;
using rangemax_int=segtree<int,[](int a,int b)->int{return max(a,b);},[]()->int{return numeric_limits<int>::min();}>;
using rangemax_ll=segtree<long long,[](long long a,long long b)->long long{return max(a,b);},[]()->long long{return numeric_limits<long long>::min();}>;
