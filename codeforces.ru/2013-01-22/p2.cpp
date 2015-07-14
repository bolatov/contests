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

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n >> t;

    vector<int> arr(n, 0);
    string s;
    cin >> s;

    for (int i = 0; i < n;i++) {
        if (s.at(i) == 'B')
            arr[i] = 1;
    }

    while (t > 0) {
        for (int i = 1; i< n; i++) {
            if (arr[i] < arr[i-1]) {
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                i++;
            }
        }
        t--;
    }

    string out = "";
    for (int i = 0; i < n;i++) {
        if (arr[i] == 0)  out += 'G';
        else              out += 'B';
    }
    cout << out << endl;

}
