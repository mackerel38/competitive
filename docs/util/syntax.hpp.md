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
  bundledCode: "#line 2 \"util/syntax.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstring syntax(string& s, vector<string>& o, int size=128) {\n    vector<int>\
    \ rankdict(size);\n    for (int i=0; i<(int)o.size(); i++) {\n        for (auto&\
    \ j : o[i]) {\n            rankdict[j] = i + 1;\n        }\n    }\n    vector<int>\
    \ ranks(s.size());\n    int rank=0;\n    for (int i=0; i<(int)s.size(); i++) {\n\
    \        if (s[i] == '(') {\n            rank += (int)o.size() + 1;\n        \
    \    ranks[i] = rank;\n        } else if (s[i] == ')') {\n            rank -=\
    \ (int)o.size() + 1;\n            ranks[i] = rank;\n        } else {\n       \
    \     ranks[i] = rank + rankdict[s[i]];\n        }\n    }\n    string re;\n  \
    \  stack<int> st;\n    for (int i=0; i<(int)s.size(); i++) {\n        if (s[i]=='('\
    \ || s[i]==')') continue;\n        if (rankdict[s[i]] == 0) {\n            re\
    \ += s[i];\n        } else if (st.empty() || ranks[st.top()]<ranks[i]) {\n   \
    \         st.push(i);\n        } else {\n            while (!st.empty() && ranks[i]<=ranks[st.top()])\
    \ {\n                re += s[st.top()];\n                st.pop();\n         \
    \   }\n            st.push(i);\n        }\n    }\n    while (!st.empty()) {\n\
    \        re += s[st.top()];\n        st.pop();\n    }\n    return re;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstring syntax(string&\
    \ s, vector<string>& o, int size=128) {\n    vector<int> rankdict(size);\n   \
    \ for (int i=0; i<(int)o.size(); i++) {\n        for (auto& j : o[i]) {\n    \
    \        rankdict[j] = i + 1;\n        }\n    }\n    vector<int> ranks(s.size());\n\
    \    int rank=0;\n    for (int i=0; i<(int)s.size(); i++) {\n        if (s[i]\
    \ == '(') {\n            rank += (int)o.size() + 1;\n            ranks[i] = rank;\n\
    \        } else if (s[i] == ')') {\n            rank -= (int)o.size() + 1;\n \
    \           ranks[i] = rank;\n        } else {\n            ranks[i] = rank +\
    \ rankdict[s[i]];\n        }\n    }\n    string re;\n    stack<int> st;\n    for\
    \ (int i=0; i<(int)s.size(); i++) {\n        if (s[i]=='(' || s[i]==')') continue;\n\
    \        if (rankdict[s[i]] == 0) {\n            re += s[i];\n        } else if\
    \ (st.empty() || ranks[st.top()]<ranks[i]) {\n            st.push(i);\n      \
    \  } else {\n            while (!st.empty() && ranks[i]<=ranks[st.top()]) {\n\
    \                re += s[st.top()];\n                st.pop();\n            }\n\
    \            st.push(i);\n        }\n    }\n    while (!st.empty()) {\n      \
    \  re += s[st.top()];\n        st.pop();\n    }\n    return re;\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/syntax.hpp
  requiredBy: []
  timestamp: '2025-08-31 22:46:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/syntax.hpp
layout: document
redirect_from:
- /library/util/syntax.hpp
- /library/util/syntax.hpp.html
title: util/syntax.hpp
---
