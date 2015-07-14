#include <set>
#include <map>
#include <unordered_map>
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

//std::string toString( long long n )
//{
//    std::ostringstream result;
//    result << n;
//    return result.str();
//}

int compare(vector<long long> &f, vector<long long> &s)
{
    int fsz = f.size();
    int ssz = s.size();
    for (int i = 0; i < min(fsz, ssz); ++i) {
        if (f[i] < s[i])      return 1;
        else if (f[i] > s[i]) return -1;
    }

    if (fsz < ssz) return 1;
    else if (fsz > ssz) return -1;

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // 281B
    long long N, a;
    cin >> N;
    vector<long long> f, s;
    long long fn = 0, sn = 0;
    bool firstLast = false;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        if (a > 0) {
            a = abs(a);
//            f += toString(a);
            f.push_back(a);
            fn += a;
            firstLast = true;
        } else {
            a = abs(a);
//            s += toString(a);
            s.push_back(a);
            sn += a;
            firstLast = false;
        }
    }

    string first = "first", second = "second";

    string res = "";
    if (fn > sn) {
        res = first;
    } else if (fn < sn) {
        res = second;
    } else {
        int cmp = compare(f, s);
        if (cmp < 0) {
            res = first;
        } else if (cmp > 0) {
            res = second;
        } else {
            res = firstLast ? first : second;
        }
    }
    cout << res << endl;

    return 0;
}
