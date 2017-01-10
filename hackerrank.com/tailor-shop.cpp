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
    int n;
    int p;
    cin >> n >> p;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    sort(a.begin(), a.end());
    long long sum = 0, mn = 0;
    for (int i : a) {
        long long q = (long long)ceil(i / (double)p);
        q = max(mn, q);
        mn = q + 1;
        sum += q;
    }

    cout << sum << endl;

    return 0;
}
