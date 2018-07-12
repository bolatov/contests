#include <bits/stdc++.h>

using namespace std;

#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T, K;
    int64 N, V;
    cin >> T;
    for (int campus = 1; campus <= T; campus++) {
        cin >> N >> K >> V;
        vector<string> vs(N);
        for (int i = 0; i < N; i++) {
            cin >> vs[i];
        }

        vector<int> vi;
        int be = (V - 1) * K % N;
        while (vi.size() < K) {
            vi.push_back(be++);
            be %= N;
        }
        
        sort(vi.begin(), vi.end());
        printf("Case #%d:", campus);
        for (int i : vi)
        {
            printf(" %s", vs[i].c_str());
        }
        cout << endl;
    }

    return 0;
}