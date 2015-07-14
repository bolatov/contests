#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
std::vector<int> partition(vector<int> &ar) {
    std::vector<int> v1;
    std::vector<int> v2;
    int p = ar[0];
    for (int i = 1; i < ar.size(); ++i) {
        if (ar[i] < p)
            v1.push_back(ar[i]);
        else
            v2.push_back(ar[i]);
    }
    v1.push_back(p);
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}
int main(void) {
    vector<int> _ar;
    int _ar_size;
    cin >> _ar_size;
    for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    _ar = partition(_ar);
    for (std::vector<int>::iterator i = _ar.begin(); i != _ar.end(); ++i) {
        cout << *i << " ";
    }

    return 0;
}
