#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool can(int m, int s) 
{
    return s >= 0 && s <= 9 * m;
}

int main(int argc, char const *argv[])
{
    int m,s;
    cin >> m >> s;

    int sum = s, sum2 = s;
    string minn = "", maxx = "";
    for (int i = 0; i < m; i++)
        for (int d = 0; d < 10; d++)
        {
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
            {
                minn += char('0' + d);
                sum -= d;
                break;
            }
        }
    
    for (int i = m-1; i >= 0; i--)
        for (int d = 9; d >= 0; d--)
        {
            if (can(i, sum2 - d))
            {
                maxx += char('0' + d);
                sum2 -= d;
                break;
            }
        }
        

    if (minn.size() != m) {
        cout << "-1 -1" << endl;
    } else {
        cout << minn << " " << maxx << endl;
    }

    return 0;
}