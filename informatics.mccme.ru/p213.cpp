#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

struct triple {
    int i, j, len;
    triple(int a, int b, int c) : i(a), j(b), len(c) {}
};

const int N = 4, M = 3;
bool is(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M &&
           !((i == 3 && j == 0) || (i == 3 && j == 2));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    queue<triple> q;
    q.push(triple(0, 0, 1));
    q.push(triple(0, 2, 1));
    q.push(triple(1, 0, 1));
    q.push(triple(1, 1, 1));
    q.push(triple(1, 2, 1));
    q.push(triple(2, 0, 1));
    q.push(triple(2, 1, 1));
    q.push(triple(2, 2, 1));

    int64 r = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int i = t.i, j = t.j, len = t.len;
        if (len == n) {
            r++;
            continue;
        }

        len++;
        if (is(i - 2, j + 1)) {
            q.push(triple(i - 2, j + 1, len));
        }
        if (is(i - 1, j + 2)) {
            q.push(triple(i - 1, j + 2, len));
        }
        if (is(i + 1, j + 2)) {
            q.push(triple(i + 1, j + 2, len));
        }
        if (is(i + 2, j + 1)) {
            q.push(triple(i + 2, j + 1, len));
        }
        if (is(i + 2, j - 1)) {
            q.push(triple(i + 2, j - 1, len));
        }
        if (is(i + 1, j - 2)) {
            q.push(triple(i + 1, j - 2, len));
        }
        if (is(i - 1, j - 2)) {
            q.push(triple(i - 1, j - 2, len));
        }
        if (is(i - 2, j - 1)) {
            q.push(triple(i - 2, j - 1, len));
        }
    }
    cout << r << endl;

    return 0;
}