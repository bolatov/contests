#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int t, n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        vector<int> v(n);
        int maxVal = -10000;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            maxVal = max(maxVal, v[i]);
        }

        int bestSum = maxVal, curSum = 0, sum = 0;
        for (int i : v) {
            int val = curSum + i;
            curSum = (val > 0) ? val : 0;
            bestSum = max(bestSum, curSum);

            sum += (i > 0 ? i : 0);
        }
        bestSum = (bestSum == 0 ? maxVal : bestSum);
        sum = (sum == 0 ? maxVal : sum);
        printf("%d %d\n", bestSum, sum);
    }
    return 0;
}