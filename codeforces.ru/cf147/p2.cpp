#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

using namespace std;

string int2str(int n) {
    std::ostringstream result;
    result << n;
    return result.str();
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    vector<vector<int>> matrix;
    for (int i = 0; i < N; i++) {
        int ci;
        cin >> ci;
        vector<int> row(ci, 0);
        matrix.push_back(row);
    }

    map<int, pair<int,int>> positions;
    vector<vector<int>> ideal_m;
    int s = 0;
    for (int i = 0; i < N; i++) {
        int len = matrix[i].size();

        vector<int> ideal_v;
        for (int j = 0; j < len; j++) {
            int val;
            cin >> val;
            matrix[i][j] = val;

            positions[val] = make_pair(i,j);
            ideal_v.push_back(++s);
        }
        ideal_m.push_back(ideal_v);
    }

    int cnt = 0;
    string res = "";
    for (int i = 0; i < N; i++) {
        int len = matrix[i].size();
        for (int j = 0; j < len; j++) {
            int val = matrix[i][j];
            int ideal_val = ideal_m[i][j];
            if (ideal_val != val) {
                cnt++;
                pair<int,int> oldPos = positions[val];
                pair<int,int> newPos = positions[ideal_val];
                positions[val] = newPos;
                positions[ideal_val] = oldPos;

                matrix[newPos.first][newPos.second] = val;

                res +=  int2str(oldPos.first+1) + " " + int2str(oldPos.second+1) + " " + 
                        int2str(newPos.first+1) + " " + int2str(newPos.second+1) + "\n"; 
            }
        }
    }

    printf("%d\n", cnt);
    cout << res;
    return 0;
}
