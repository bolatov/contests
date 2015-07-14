#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    std::vector<pair<ll, ll> > vpii;
    ll minDiff = -1;
    for (int i = 1; i < n; ++i) {
        int diff = v[i] - v[i - 1];
        pair<ll, ll> p = make_pair(v[i - 1], v[i]);
        if (vpii.empty()) {
            minDiff = diff;
            vpii.push_back(p);
            continue;
        }

        if (diff == minDiff) {
            vpii.push_back(p);
        } else if (diff < minDiff) {
            minDiff = diff;
            vpii.clear();
            vpii.push_back(p);
        }
    }
    for (pair<ll, ll> p : vpii) {
        cout << p.first << " " << p.second << " ";
    }
    printf("\n");
    return 0;
}
