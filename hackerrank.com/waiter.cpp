#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1e6 + 7;

int main() {
    int N, Q, V;
    cin >> N >> Q;
    
    // read input into stack at position 0
    vector<stack<int>> vi(2 * Q + 1, stack<int>());
    while(N--) {
        cin >> V;
        vi[0].push(V);
    }
    
    // Sieve of Eratosthenes
    vector<bool> u(MAX, 1);
    vector<int> v;
    for (int i = 2; v.size() <= Q; i++) {
        if (u[i]) {
            v.push_back(i);
            for (int j = i + i; j < MAX; j += i) u[j] = 0;
        }
    }
    
    // do reordering according to the problem description
    for (int k = 0; k < Q; k++) {
        int i = k * 2;
        while (!vi[i].empty()) {
            int top = vi[i].top();
            vi[i].pop();
            
            if (top % v[k] == 0) vi[i + 1].push(top);
            else vi[i + 2].push(top);
        }
    }
    
    // print the results
    for (int i = 1; i < vi.size(); i++) {
        while (!vi[i].empty()) {
            cout << vi[i].top() << endl;
            vi[i].pop();
        }
    }
    
    return 0;
}
