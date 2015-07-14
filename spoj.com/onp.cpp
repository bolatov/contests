#include <stack>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tests;
    cin >> tests;
    char chars[] = {'+', '-', '*', '/', '^'};
    map<char,int> m;
    for (int i = 0; i < 5; ++i)
    {
        m[chars[i]] = i;
    }
    for (int itest = 0; itest < tests; ++itest)
    {
        string str;
        cin >> str;
        vector<char> ans;
        stack<char> st;
        for (int i = 0; i < str.size(); ++i)
        {
            char c = str[i];
            if (c >= 'a' && c <= 'z') {
                ans.push_back(c);
                continue;
            }

            if (c == '(') {
                st.push(c);
                continue;
            }

            if (c == ')') {
                while(st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove '('
                continue;
            }

            if (st.empty() || st.top() == '(') {
                st.push(c);
            } else {
                char ctop = st.top();
                int ptop = m[ctop];
                int pnew = m[c];
                if (ptop > pnew) {
                    st.pop();
                    ans.push_back(ctop);
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            if (c != '(' && c != ')')
                ans.push_back(c);
        }

        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
