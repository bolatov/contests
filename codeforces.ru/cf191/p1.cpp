#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
        scanf("%d", &arr[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int temp = 0;
            for (int k = 0; k < n; ++k) {
                if (i <= k && k <= j)
                    temp += 1- arr[k];
                else
                    temp += arr[k];
            }
            res = max(res, temp);
        }
    }
    printf("%d\n", res);
    return 0;
}

