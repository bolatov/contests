#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    map<string, string> fs, sf;
    string fir, sec;
    for (int i = 0; i < m; ++i) {
        cin >> fir >> sec;
        fs[fir] = sec;
        sf[sec] = fir;
    }
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (fs.find(str) != fs.end()) {
            fir = str;
            sec = fs[fir];
        } else {
            sec = str;
            fir = sf[sec];
        }
        cout << (fir.size() <= sec.size() ? fir : sec) << " ";
    }
    cout << endl;
    return 0;
}