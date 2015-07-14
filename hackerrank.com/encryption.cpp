#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    int h = floor(sqrt((double)n)), w = ceil(sqrt((double)n));
    while (h * w < n) {
        h++;
    }
    // printf("h=%d, w=%d\n", h, w);
    s += string(w * h - n, ' ');
    for (int j = 0; j < w; ++j) {
        char ch = ' ';
        for (int i = 0; i < h; ++i) {
            // printf("%d,", j + i * w);
            ch = s[j + i * w];
            printf("%c", ch);
        }
        if (ch != ' ')
            printf(" ");
    }
    printf("\n");
    return 0;
}
