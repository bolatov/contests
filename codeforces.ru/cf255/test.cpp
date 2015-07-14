#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long long minValue;

    long long N, v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v;
        minValue = min(minValue, v);
    }

    cout << minValue << endl;
}
