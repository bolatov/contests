#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    if (k > n) {
        cout << "-1" << endl;
        return 0;
    }

    printf("%d %d\n", arr[n-k], 0);
    // cout << arr[n-k] << " "<< endl;    
}