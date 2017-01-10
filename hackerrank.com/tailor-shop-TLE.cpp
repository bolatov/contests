#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    int p;
    cin >> n >> p;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    sort(a.begin(), a.end());
    set<int> si;

    int mx = INT_MAX;
    for (int i : a) {
        int q = (int)ceil(i / (double)p);
        q = min(mx, q);
        mx = q + 1;
        for (; si.find(q) != si.end(); q++)
            ;
        si.insert(q);
        printf("%d -> %d\n", i, q);
    }

    long long sum = 0;
    for (long long i : si)
        sum += i;
    cout << sum << endl;

    return 0;
}
