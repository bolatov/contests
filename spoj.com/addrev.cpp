#include <iostream>
#include <cstdio>

using namespace std;

int rev(int i) {
    int j = 0;
    while(i>0) {
        j = j*10 + (i%10);
        i /= 10;
    }
    return j;
}

int main() {
    int N, x, y, z;
    cin >> N;
    while(N-- >0) {
        cin >> x >> y;
        x = rev(x);
        y = rev(y);
        z = x+y;
        cout << rev(z) << endl;
    }
    return 0;
}
