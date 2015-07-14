#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    scanf("%i", &n);
    while (n!=42) {
        printf("%i\n", n);
        scanf("%i", &n);
    }
    return 0;
}