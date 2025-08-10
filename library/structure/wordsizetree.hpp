#include <bits/stdc++.h>
using namespace std;
struct wordsizetree {
    int size;
    vector<vector<unsigned long long>> a;
    static int highbit(unsigned long long x){
        if(x == 0) return 0;
        return 63 - __builtin_clzll(x);
    }
    static int lowbit(unsigned long long x){
        if(x == 0) return 64;
        return __builtin_ctzll(x);
    }
    wordsizetree() = default;
    wordsizetree(int n){
        size = n;
        int t = n;
        do {
            vector<unsigned long long> b(t/64+1);
            a.emplace_back(move(b));
            t /= 64;
        } while(t);
    }
    wordsizetree(vector<int> v) : wordsizetree(v.size()) {
        for (int i=0; i<(int)v.size(); i++) {
            if (v[i]) {
                insert(i);
            }
        }
    }
    void insert(int x){
        for(auto& a : a){
            a[x/64] |= 1ULL << (x % 64);
            x /= 64;
        }
    }
    void erase(int x){
        for(auto& a : a){
        a[x/64] &= ~(1ULL << (x % 64));
        if(a[x/64]) return;
        x /= 64;
        }
    }
    int count(int x) {
        return (int)((a[0][x/64] >> (x%64)) & 1);
    }
    // x<=y となる最小のy を返す
    int minright(int x) {
        if(x < 0) x = 0;
        if(size <= x) return size;
        int d = 0, i = x;
        while(true){
            if(d >= (int)a.size()) return size;
            if(i/64 >= (int)a[d].size()) return size;
            unsigned long long m = a[d][i/64] & ((~(unsigned long long)0) << (i%64));
            if(!m){d++; i/=64; i++;}
            else{
                int to = lowbit(m);
                i = i/64*64 + to;
                if(d == 0) break;
                i *= 64;
                d--;
            }
        }
        return i;
    }
    // x<=y を満たす最小のy を返す
    int maxleft(int x) {
        if(x < 0) return -1;
        if(size <= x) x = size-1;
        int d = 0, i = x;
        while(true){
            if(i < 0) return -1;
            if(d >= (int)a.size()) return -1;
            unsigned long long m = a[d][i/64] & ~((~(unsigned long long)1) << (i%64));
            if(!m){ d++; i /= 64; i--; }
            else{
                int to = highbit(m);
                i = i/64*64 + to;
                if(d == 0) break;
                i *= 64;
                i += 64-1;
                d--;
            }
        }
        return i;
    }
};