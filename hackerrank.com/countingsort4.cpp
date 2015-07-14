#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n;
    vector<int> oriNum(n);
    vector<string> oriStr(n);
    vector<int> count(100, 0);
    vector<int> indices(100, 0);
    vector<int> output(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> oriNum[i] >> oriStr[i];
        count[oriNum[i]]++;
    }

    indices[0] = 0;
    for (int i = 1; i < count.size(); ++i) {
        indices[i] = indices[i - 1] + count[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        int num = oriNum[i];
        output[indices[num]++] = i;
    }

    int bar = n / 2;
    for (int i = 0; i < n; ++i) {
        int index = output[i];
        if (index < bar)
            cout << "-";
        else
            cout << oriStr[index];
        cout << " ";
    }

    return 0;
}