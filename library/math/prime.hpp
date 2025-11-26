#pragma once
#include <bits/stdc++.h>
using namespace std;
// 素数判定 O(log n)
bool isprime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int flag = 1;
    if (n < 4759123141LL) flag = 0;
    vector<vector<long long>> tests = {{2, 7, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};
    long long s = 0, d = n - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    for (auto a : tests[flag]) {
        if (n <= a) return true;
        __int128_t x = 1, a2=a%n, d2 = d;
        while (d2) {
            if (d2 & 1) x = x * a2 % n;
            a2 = a2 * a2 % n;
            d2 >>= 1;
        }
        if (x != 1) {
            long long t;
            for (t = 0; t < s; ++t) {
                if (x == n - 1) break;
                x = x * x % n;
            }
            if (t == s) return false;
        }
    }
    return true;
}
// n 以下の素数を列挙する O(n log log n)
vector<int> enumprimes(long long n) {
    vector<char> primeflag(n+1);
    vector<int> re;
    for (long long i=2; i<=n; i++) {
        if (primeflag[i]) continue;
        re.push_back(i);
        for (long long j=i*i; j<=n; j+=i) {
            primeflag[j] = true;
        }
    }
    return re;
}
void inner_factorize(long long n, vector<long long>& factors) {
    if (n <= 1) return;
    if (isprime(n)) {
        factors.push_back(n);
        return;
    }
    if (n % 2 == 0) {
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        inner_factorize(n, factors);
        return;
    }
    while (true) {
        __int128_t x = rand() % (n - 2) + 2;
        __int128_t y = x;
        __int128_t c = rand() % (n - 1) + 1;
        __int128_t m = 1;
        while (m == 1) {
            x = (x * x + c) % n;
            y = (y * y + c) % n;
            y = (y * y + c) % n;
            m = gcd((long long)(x - y + n), n);
            if (m == n) break;
        }
        if (m != n) {
            inner_factorize(m, factors);
            inner_factorize(n / m, factors);
            return;
        }
    }
}
// 素因数分解をする O(n^0.25)
vector<long long> factorize(long long n) {
    vector<long long> re;
    inner_factorize(n, re);
    return re;
}