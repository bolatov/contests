/* Sample program illustrating input/output */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    std::vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end(), greater<int>());

    int x = 0;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && i % K == 0)
            x++;
        result += (x + 1) * C[i];
    }

    cout << result << "\n";

    return 0;
}
