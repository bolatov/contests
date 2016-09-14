#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, char> i, pair<int, char> j) {
    return (((i.first > j.first) && (i.second > j.second)));
}

int main() {
    string ws;
    getline(cin, ws);
    istringstream ss(ws);

    vector<string> vw;
    for (string w; ss >> w;) {
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        vw.push_back(w);
    }

    int n, hid;
    string reviews;
    cin >> n;

    map<int, int> hcnt;
    for (int i = 0; i < n; i++) {
        cin >> hid;
        getline(cin, reviews);

        cout << "deb: " << hid << " : " << reviews << endl;

        transform(reviews.begin(), reviews.end(), reviews.begin(), ::tolower);
        int cnt = 0;
        for (string w : vw) {
            size_t found = reviews.find_first_of(w);
            while (found != string::npos) {
                cnt++;
                found = reviews.find_first_of(w, found + 1);
            }
        }

        if (hcnt.find(hid) == hcnt.end()) {
            hcnt[hid] = 0;
        }
        hcnt[hid] = hcnt[hid] + cnt;
    }

    vector<pair<int, int>> vp;
    for (auto it = hcnt.begin(); it != hcnt.end(); it++) {
        vp.push_back({it->second, it->first});
        cout << "deb: " << it->first << " " << it->second << endl;
    }
    sort(vp.begin(), vp.end(), cmp);

    for (auto p : vp) {
        printf("%d ", p.second);
    }
    printf("\n");

    return 0;
}