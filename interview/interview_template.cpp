#include <bits/stdc++.h>

using namespace std;

struct pair_comp {
    bool operator()(pair<int, int> const& lhs, pair<int, int> const& rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

// struct pair_comp {
//     bool operator()(pair<int, int> const& lhs, pair<int, int> const& rhs) {
//         if (lhs.first == rhs.first) return lhs.second < rhs.second;
//         return lhs.first < rhs.first;
//     }
// };

void comparePairs() {
    vector<pair<int, int>> vpii = {{4, 0}, {1, 3}, {1, 2}, {1, 1}};
    sort(vpii.rbegin(), vpii.rend(), pair_comp());
    // sort(vpii.begin(), vpii.end());
    for (auto pii : vpii) {
        printf("%d : %d\n", pii.first, pii.second);
    }
}

void mapIterator() {
    map<int, int> mp;
}

vector<string> split(string s) {
    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    return vstrings;
}

void readSentence() {
    printf("Read sentence: \n");
    vector<string> vs;
    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << "string: " << s << endl;

    vs = split(s);
    for (int i = 0; i < (int)vs.size(); ++i) {
        cout << i << " : '" << vs[i] << "'" << endl;
    }

    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "four === " << s << endl;

    int a, b;
    cin >> a >> b;
    printf("%d %d\n", a, b);
    printf("==================== END Read sentence ================ \n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // comparePairs();
    readSentence();
    return 0;
}