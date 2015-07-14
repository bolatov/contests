#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> primes;
map<int, vector<int> > eqk;

const int MAX_VALUE = 1e7;

void initPrimes() {
    vector<bool> u(MAX_VALUE + 1, 1);
    for (int i = 2; i <= MAX_VALUE; ++i) {
        if (u[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= MAX_VALUE; j += i) {
                u[j] = 0;
            }
        }
    }
}

void initEqk() {
    std::vector<int> v(MAX_VALUE + 1, 0);
    for (int p : primes) {
        for (int i = p; i <= MAX_VALUE; i += p) {
            v[i]++;
        }
    }

    for (int i = 2; i < (int)v.size(); ++i) {
        int k = v[i];
        eqk[k].push_back(i);
    }
}

int solve(int a, int b, int k) {
    int ans = 0;
    for (int i : eqk[k]) {
        ans += (a <= i && i <= b);
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    initPrimes();
    initEqk();

    int t, a, b, k;
    cin >> t;
    for (int itest = 1; itest <= t; ++itest) {
        cin >> a >> b >> k;
        int ans = solve(a, b, k);
        printf("Case #%d: %d\n", itest, ans);
    }
    return 0;
}