#include <iostream>

using namespace std;

int main()
{
    int n,m;//,ans=-1;
    cin >> n >> m;

    for (int k = 1; k*m <= n; ++k) {
        int a1 = n-m*k;
        int a2 = n-2*a1;

        if (2*a1+a2==n && a1>=0 && a2>=0) {
            cout << m*k << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}

