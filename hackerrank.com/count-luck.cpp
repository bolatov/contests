#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

string ans;
int iend, jend, k;
void solve(vector<string> &v, vector<vector<int> > &u, int i, int j,
           int steps) {
    // printf("(%d,%d) steps=%d\n", i, j, steps);
    if (i == iend && j == jend) {
        if (k == steps)
            ans = "Impressed";
        return;
    }
    if (steps > k)
        return;

    int cnt = 0;
    if (j + 1 < v[0].size() && v[i][j + 1] != 'X' && !u[i][j + 1])
        cnt++;
    if (i + 1 < v.size() && v[i + 1][j] != 'X' && !u[i + 1][j])
        cnt++;
    if (j - 1 >= 0 && v[i][j - 1] != 'X' && !u[i][j - 1])
        cnt++;
    if (i - 1 >= 0 && v[i - 1][j] != 'X' && !u[i - 1][j])
        cnt++;

    steps += (cnt > 1);

    if (j + 1 < v[0].size() && v[i][j + 1] != 'X' && !u[i][j + 1]) {
        u[i][j + 1] = 1;
        solve(v, u, i, j + 1, steps);
    }
    if (i + 1 < v.size() && v[i + 1][j] != 'X' && !u[i + 1][j]) {
        u[i + 1][j] = 1;
        solve(v, u, i + 1, j, steps);
    }
    if (j - 1 >= 0 && v[i][j - 1] != 'X' && !u[i][j - 1]) {
        u[i][j - 1] = 1;
        solve(v, u, i, j - 1, steps);
    }
    if (i - 1 >= 0 && v[i - 1][j] != 'X' && !u[i - 1][j]) {
        u[i - 1][j] = 1;
        solve(v, u, i - 1, j, steps);
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int t, n, m;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<int> > u(n, vector<int>(m, 0));
        int istart, jstart;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            int spos = v[i].find('M');
            int tpos = v[i].find('*');
            if (spos != string::npos) {
                istart = i;
                jstart = spos;
            }
            if (tpos != string::npos) {
                iend = i;
                jend = tpos;
            }
        }
        cin >> k;
        ans = "Oops!";
        u[istart][jstart] = 1;
        solve(v, u, istart, jstart, 0);
        cout << ans << endl;
    }
    return 0;
}