#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n;
    std::vector<int> a(100), b(100, 0);
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in >> s;
        a[in]++;
    }

    b[0] = a[0];
    cout << b[0] << " ";
    for (int i = 1; i < a.size(); ++i) {
        b[i] = a[i] + b[i - 1];
        cout << b[i] << " ";
    }

    return 0;
}