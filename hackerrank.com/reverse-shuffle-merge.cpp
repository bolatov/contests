#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(std::vector<int> &u) {
    for (int i = 0; i < u.size(); ++i) {
        if (u[i])
            printf("  %c:%d\n", (char)(i + 'a'), u[i]);
    }
}

bool check(string s, vector<int> u, int pos) {
    // puts("before:");
    // printArray(u);
    for (int i = pos; i < s.size(); ++i) {
        char ch = s[i];
        if (u[ch - 'a'])
            u[ch - 'a']--;
    }
    // puts("\nafter:");
    // printArray(u);
    for (int i : u) {
        if (i > 0)
            return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    std::vector<int> counts(26, 0), need(26, 0);
    for (char ch : s) {
        counts[ch - 'a']++;
    }
    for (int i = 0; i < counts.size(); ++i) {
        need[i] = counts[i] / 2;
    }
    reverse(s.begin(), s.end());
    std::vector<char> ans;
    for (int i = 0; ans.size() < s.size() / 2;) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            // printf("%c\n", ch);
            if (need[ch - 'a'] && s.find(ch, i) != string::npos) {
                int pos = s.find(ch, i);
                if (check(s, need, pos)) {
                    i = s.find(ch, i);
                    // printf("  ch=%c, pos=%d\n", ch, i);
                    i++;
                    need[ch - 'a']--;
                    ans.push_back(ch);
                    break;
                }
            }
        }
    }
    for (char ch : ans)
        printf("%c", ch);
    cout << endl;
    return 0;
}
