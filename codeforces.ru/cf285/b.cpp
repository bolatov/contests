#include <bits/stdc++.h>

using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int q;
    cin >> q;
    string oh, nh;
    // map<string, string> m, mm;
    std::vector<pair<string, string> > v;
    set<string> all;
    for (int ireq = 0; ireq < q; ++ireq) {
        cin >> oh >> nh;
        if (all.find(nh) == all.end()) {
            int index = -1;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].second == oh) {
                    index = i;
                }
            }
            if (index < 0) {
                v.push_back({ oh, nh });
            } else {
                v[index].second = nh;
            }
        }
    }
    cout << v.size() << endl;
    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
