#pragma once
#include <bits/stdc++.h>
using namespace std;
template <int char_size, int base>
struct Trie {
    struct datum {
        vector<int> next;
        vector<int> accept;
        int c;
        int common;
        datum(int _c) : c(_c), common(0) { next.assign(char_size, -1); }
    };
    vector<datum> data;
    int root;
    Trie() : root(0) { data.push_back(datum(root)); }
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i=0; i<word.size(); i++) {
            int c = word[i] - base;
            int &next_id = data[node_id].next[c];
            if (next_id == -1) {
                next_id = data.size();
                data.push_back(datum(c));
            }
            data[node_id].common++;
            node_id = next_id;
        }
        data[node_id].common++;
        data[node_id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, data[0].common);
    }
    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i=0; i<word.size(); i++) {
            int c = word[i] - base;
            int &next_id = data[node_id].next[c];
            if (next_id == -1) {
                return false;
            }
            node_id = next_id;
        }
        return prefix ? true : 0<data[node_id].accept.size();
    }
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }
    int count() const {
        return data[0].common;
    }
    int size() const {
        return data.size();
    }
};