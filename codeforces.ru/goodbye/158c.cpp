#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string cmd, param;
    vector<string> cur;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd[0] == 'p') {
            cout << "/";
            for (string str : cur) {
                cout << str << "/";
            }
            cout << endl;
        } else {
            cin >> param;
            if (param[0] == '/') {
                cur.clear();
                param.erase(param.begin());
            }
            string token = "";
            for (int j = 0; j < (int)param.size(); ++j) {
                if (param[j] != '/')
                    token += param[j];
                if (param[j] == '/' || j == (int)param.size() - 1) {
                    if (token == "..")
                        cur.pop_back();
                    else
                        cur.push_back(token);
                    token = "";
                }
            }
        }
    }

    return 0;
}