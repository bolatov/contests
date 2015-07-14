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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // 281C
    long long N;
    cin >> N;
    vector<long long> df(N,0);
    for (int i = 0; i < N; ++i) {
        cin >> df[i];
    }

    long long M;
    cin >> M;
    vector<long long> ds(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> ds[i];
    }

    sort(df.begin(), df.end());
    sort(ds.begin(), ds.end());

    long long diff = 0, score1 = 0, score2 = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && df[i] == df[i-1]) continue;

        long long d = df[i];
        long long sc1 = i*2 + (N-i)*3;

        int l = 0, r = M-1, ind=M;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (ds[mid] >= d) {
                r = mid-1;
                ind = mid;
            } else {
                l = mid+1;
            }
        }
        long long sc2 = ind*2 + (M-ind)*3;

        if (i == 0) {
            diff = sc1-sc2;
            score1 = sc1;
            score2 = sc2;
        }

        if (sc1-sc2 > diff) {
            diff = sc1-sc2;
            score1 = sc1;
            score2 = sc2;
        } else if (sc1-sc2 == diff && sc1 > score1) {
            score1 = sc1;
            score2 = sc2;
        }
    }

    // TODO
    // start from team 2
//    for (int i = 0; i < M; ++i) {
//        if (i > 0 && ds[i] == ds[i-1]) continue;

//        long long d = ds[i];
//        long long sc2 = i*2 + (M-i)*3;

//        int l = 0, r = N-1, ind=N;
//        while (l < r) {
//            int mid = (l+r) / 2;
//            if (df[mid] >= d) {
//                r = mid-1;
//                ind = mid;
//            } else {
//                l = mid+1;
//            }
//        }
//        long long sc1 = ind*2 + (N-ind)*3;

//        if (sc1-sc2 > diff) {
//            diff = sc1-sc2;
//            score1 = sc1;
//            score2 = sc2;
//        } else if (sc1-sc2 == diff && sc1 > score1) {
//            score1 = sc1;
//            score2 = sc2;
//        }
//    }

    cout << score1 << ":" << score2 << endl;

    return 0;
}
