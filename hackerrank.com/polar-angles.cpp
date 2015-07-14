#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define PI 3.14159265

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    double x, y;
    // deg -> dist -> [(x,y),...]
    map<int, map<int, vector<pair<int, int> > > > m;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        double deg;
        if (x == 0) {
            deg = (y > 0) ? 90 : 270;
        } else if (y == 0) {
            deg = (x > 0) ? 0 : 180;
        } else {
            deg = atan(y / x) * 180 / PI;
            if (x < 0 && y > 0) // II quadrant
                deg += 180;
            else if (x < 0 && y < 0) // III quadrant
                deg += 180;
            else if (x > 0 && y < 0) // IV quadrant
                deg += 360;
        }

        int ideg = (int)(deg * 1e4);
        int idist = (int)(sqrt(pow(x, 2) + pow(y, 2)) * 1e3);

        pair<int, int> p = make_pair(x, y);
        vector<pair<int, int> > v;
        v.push_back(p);
        map<int, std::vector<pair<int, int> > > mv;
        mv[idist] = v;
        if (m.find(ideg) == m.end()) {
            m[ideg] = mv;
        } else {
            if (m[ideg].find(idist) == m[ideg].end()) {
                m[ideg][idist] = v;
            } else {
                m[ideg][idist].insert(m[ideg][idist].end(), p);
            }
        }

        // double dist = (sqrt(pow(x, 2) + pow(y, 2)));
        // printf("x=%.0f,y=%.0f\n", x, y);
        // printf("degree:   %.2f\n", deg);
        // printf("distance: %.2f\n\n", dist);
    }

    for (auto mit = m.begin(); mit != m.end(); ++mit) {
        for (auto dit = (mit->second).begin(); dit != (mit->second).end();
             dit++) {
            for (auto vit = dit->second.begin(); vit != dit->second.end();
                 ++vit) {
                printf("%d %d\n", (int)(*vit).first, (int)(*vit).second);
            }
        }
    }

    return 0;
}
