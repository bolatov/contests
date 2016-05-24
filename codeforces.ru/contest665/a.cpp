#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int to_num(const string &Text) {
    istringstream ss(Text);
    int result;
    return ss >> result ? result : 0;
}

bool is(int i, int j, int k) { return i <= k && k <= j; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    string s;
    cin >> s;
    int h = to_num(s.substr(0, 2));
    int m = to_num(s.substr(3, 2));

    // A -> B
    int start = (h - 5) * 60 + m;
    int end = start + ta;

    printf("+ [%2d:%2d] - [%2d:%2d]\n\n", start / 60 + 5, start % 60,
           end / 60 + 5, end % 60);

    // B -> A
    int r = 0;
    for (int i = 0; i <= end; i += b) {
        if (is(start, end, i)) {
            r++;
            printf("> [%2d:%2d] - [%2d:%2d]\n", i / 60 + 5, i % 60,
                   (i + tb) / 60 + 5, (i + tb) % 60);
        }
    }
    printf("%d\n", r);
    return 0;
}