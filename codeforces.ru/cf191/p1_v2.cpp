#include <iostream>
#include <cstdio>

using namespace std;

//O(n) Solution

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    int SIZE = 100;
    int a[SIZE], b[SIZE], sum=0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i]) b[i] = -1;
        else      b[i] = 1;
    }

    int s[SIZE], temp=0;
    s[0] = b[0];
    temp = s[0];
    for (int i = 1; i < N; i++) {
        if (s[i-1] > 0)
            s[i] = s[i-1] + b[i];
        else
            s[i] = b[i];
        temp = max(temp, s[i]);
    }
    printf("%d\n", sum+temp);

    return 0;
}
