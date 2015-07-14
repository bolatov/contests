#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    std::vector<int> v(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        if (i > 0)
        {
            v[i] += v[i-1];
        }
    }

    int m, x;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        std::vector<int>::iterator it = upper_bound(v.begin(), v.end(), x);
        int index = it - v.begin();
        if (index > 0 && v[index-1] == x) index--;
        cout << (index + 1) << endl;
    }

    return 0;
}