#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> getPrimeNumbers(int UPPER) {
    list<int> ps;
    for (int i = 2; i < UPPER; i++) {
        ps.push_back(i);
    }

    list<int>::iterator it, it1;
    for (it = ps.begin(); it != ps.end(); ++it) {
        it1 = it;
        it1++;
        while (it1 != ps.end()) {
            if (*it1 % *it == 0)    
                it1 = ps.erase(it1);
            else
                it1++;
        }
    }

    vector<int> primes;
    for (it=ps.begin(); it != ps.end(); ++it) {
        primes.push_back(*it);
        // primes.insert(*it);
    }

    return primes;
}

bool isPrime(vector<int>& ps, int n) {
    int sq = sqrt(n) + 1;
    for (int i = 0; i < sq; ++i)
    {
        if (ps[i] == n) return true;
        if (n % ps[i] == 0) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxNum = 1000000000;
    set<int> pset, npset;
    int sq = (int) sqrt(maxNum);
    vector<int> ps = getPrimeNumbers(/*pset, npset, */sqrt(sq));

    for (int i = 0; i < ps.size(); ++i)
    {
        printf("%d\n", ps[i]);
    }
    printf("In total = %d\n", (int) ps.size());

    int tests;
    scanf("%i", &tests);
    for (int itest = 0; itest < tests; ++itest)
    {
        int m,n;
        // cin >> m >> n;
        scanf("%d %d", &m, &n);
        
        for (int i = m; i <= n; ++i)
        {
            if (npset.find(i) != npset.end()) {
                continue;
            }
            if (pset.find(i) != pset.end()) {
                printf("%d\n", i);
                continue;
            }
            if (isPrime(ps, i)) {
                printf("%d\n", i);
                pset.insert(i);
            }
        }

        // cout << endl;
        printf("\n");
    }

    return 0;
}