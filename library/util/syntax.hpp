#pragma once
#include <bits/stdc++.h>
using namespace std;

string syntax(string& s, vector<string>& o, int size=128) {
    vector<int> rankdict(size);
    for (int i=0; i<(int)o.size(); i++) {
        for (auto& j : o[i]) {
            rankdict[j] = i + 1;
        }
    }
    vector<int> ranks(s.size());
    int rank=0;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == '(') {
            rank += (int)o.size() + 1;
            ranks[i] = rank;
        } else if (s[i] == ')') {
            rank -= (int)o.size() + 1;
            ranks[i] = rank;
        } else {
            ranks[i] = rank + rankdict[s[i]];
        }
    }
    string re;
    stack<int> st;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i]=='(' || s[i]==')') continue;
        if (rankdict[s[i]] == 0) {
            re += s[i];
        } else if (st.empty() || ranks[st.top()]<ranks[i]) {
            st.push(i);
        } else {
            while (!st.empty() && ranks[i]<=ranks[st.top()]) {
                re += s[st.top()];
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        re += s[st.top()];
        st.pop();
    }
    return re;
}