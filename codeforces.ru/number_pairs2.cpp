// Number pairs
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;

int gcd (int a, int b) {
    if (b == 1) return a-1;
    if (b == 0) return 10000000;
	int res = a / b + gcd(b, a%b);
	cout << res << endl;
    return res;
}

int main ()
{
    int n, answ = 10000000;
    n = 7;//~ cin >> n;
    for (int i = 0; i < n; i++)
        answ = min(answ, gcd(n, i));
    if (n == 1) answ = 0;
	cout << endl << endl;
    cout << answ << endl;
    return 0;
}
