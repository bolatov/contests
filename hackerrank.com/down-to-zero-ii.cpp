#include <bits/stdc++.h>
using namespace std;

// Solution from discussions
int main() {
    int Q, N;
    cin >> Q;
    while (Q--) {
        cin >> N;
        queue<pair<int, int>> q;
        q.push({N, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first <= 4) {
                printf("%d\n", p.first == 4 ? p.second + 3 : p.second + p.first);
                break;
            }
            
            q.push({p.first - 1, p.second + 1});
            for (int i = sqrt(p.first); i > 1; --i) {
                if (p.first % i == 0) {
                    q.push({p.first / i, p.second + 1});
                }
            }
        }
    }
    return 0;
}
