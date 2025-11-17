---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <int char_size, int base>\nstruct Trie {\n    struct datum {\n\
    \        vector<int> next;\n        vector<int> accept;\n        int c;\n    \
    \    int common;\n        datum(int _c) : c(_c), common(0) { next.assign(char_size,\
    \ -1); }\n    };\n    vector<datum> data;\n    int root;\n    Trie() : root(0)\
    \ { data.push_back(datum(root)); }\n    void insert(const string &word, int word_id)\
    \ {\n        int node_id = 0;\n        for (int i=0; i<word.size(); i++) {\n \
    \           int c = word[i] - base;\n            int &next_id = data[node_id].next[c];\n\
    \            if (next_id == -1) {\n                next_id = data.size();\n  \
    \              data.push_back(datum(c));\n            }\n            data[node_id].common++;\n\
    \            node_id = next_id;\n        }\n        data[node_id].common++;\n\
    \        data[node_id].accept.push_back(word_id);\n    }\n    void insert(const\
    \ string &word) {\n        insert(word, data[0].common);\n    }\n    bool search(const\
    \ string &word, bool prefix = false) {\n        int node_id = 0;\n        for\
    \ (int i=0; i<word.size(); i++) {\n            int c = word[i] - base;\n     \
    \       int &next_id = data[node_id].next[c];\n            if (next_id == -1)\
    \ {\n                return false;\n            }\n            node_id = next_id;\n\
    \        }\n        return prefix ? true : 0<data[node_id].accept.size();\n  \
    \  }\n    bool start_with(const string &prefix) {\n        return search(prefix,\
    \ true);\n    }\n    int count() const {\n        return data[0].common;\n   \
    \ }\n    int size() const {\n        return data.size();\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <int\
    \ char_size, int base>\nstruct Trie {\n    struct datum {\n        vector<int>\
    \ next;\n        vector<int> accept;\n        int c;\n        int common;\n  \
    \      datum(int _c) : c(_c), common(0) { next.assign(char_size, -1); }\n    };\n\
    \    vector<datum> data;\n    int root;\n    Trie() : root(0) { data.push_back(datum(root));\
    \ }\n    void insert(const string &word, int word_id) {\n        int node_id =\
    \ 0;\n        for (int i=0; i<word.size(); i++) {\n            int c = word[i]\
    \ - base;\n            int &next_id = data[node_id].next[c];\n            if (next_id\
    \ == -1) {\n                next_id = data.size();\n                data.push_back(datum(c));\n\
    \            }\n            data[node_id].common++;\n            node_id = next_id;\n\
    \        }\n        data[node_id].common++;\n        data[node_id].accept.push_back(word_id);\n\
    \    }\n    void insert(const string &word) {\n        insert(word, data[0].common);\n\
    \    }\n    bool search(const string &word, bool prefix = false) {\n        int\
    \ node_id = 0;\n        for (int i=0; i<word.size(); i++) {\n            int c\
    \ = word[i] - base;\n            int &next_id = data[node_id].next[c];\n     \
    \       if (next_id == -1) {\n                return false;\n            }\n \
    \           node_id = next_id;\n        }\n        return prefix ? true : 0<data[node_id].accept.size();\n\
    \    }\n    bool start_with(const string &prefix) {\n        return search(prefix,\
    \ true);\n    }\n    int count() const {\n        return data[0].common;\n   \
    \ }\n    int size() const {\n        return data.size();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
