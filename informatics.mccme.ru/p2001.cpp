#include <bits/stdc++.h>

using namespace std;

const string cst = "-1";
string s, t;
unordered_map<string, pair<string, int>> mp;

void f(string k) {
    stack<string> st;
    for (string w = k; w != cst; w = mp[w].first) {
        st.push(w);
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> s >> t;
    mp[s] = {cst, 0};

    queue<string> q;
    q.push(s);
    while (!q.empty()) {
        string k = q.front();
        q.pop();

        // cout << k << endl;

        // 1
        if (k[0] != '9') {
            string z = k;
            ++z[0];
            if (z == t) {
                mp[z] = {k, mp[k].second + 1};
                f(z);
                break;
            } else if (mp.find(z) == mp.end() || mp[k].second + 1 < mp[z].second) {
                mp[z] = {k, mp[k].second + 1};
                q.push(z);
            }
        }

        // 2
        if (k[k.size() - 1] != '1') {
            string z = k;
            --z[k.size() - 1];
            if (z == t) {
                mp[z] = {k, mp[k].second + 1};
                f(z);
                break;
            } else if (mp.find(z) == mp.end() || mp[k].second + 1 < mp[z].second) {
                mp[z] = {k, mp[k].second + 1};
                q.push(z);
            }
        }

        // 3
        string y = k.substr(1) + k[0];
        if (y == t) {
            mp[y] = {k, mp[k].second + 1};
            f(y);
            break;
        } else if (mp.find(y) == mp.end() || mp[k].second + 1 < mp[y].second) {
            mp[y] = {k, mp[k].second + 1};
            q.push(y);
        }

        // 4
        string x = k[k.size() - 1] + k.substr(0, k.size() - 1);
        if (x == t) {
            mp[x] = {k, mp[k].second + 1};
            f(x);
            break;
        } else if (mp.find(x) == mp.end() || mp[k].second + 1 < mp[x].second) {
            mp[x] = {k, mp[k].second + 1};
            q.push(x);
        }
    }

    return 0;
}