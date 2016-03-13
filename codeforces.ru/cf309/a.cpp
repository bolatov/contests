#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int sz = (int)s.size();

    set<string> ss;
    for (int i = 0; i < sz; ++i)
    {
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            string t = s.substr(0, i) + ch + s.substr(i);
            // cout << t << endl;
            ss.insert(t);
        }
    }
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        string t = s;
        ss.insert(s + ch);
    }
    cout << ss.size() << endl;
    return 0;
}