#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, a;
    string s;
    cin >> n;
    std::vector<int> v(100);
    std::vector<vector<string> > vs(100);
    for (int i = 0; i < n; ++i) {
        cin >> a >> s;
        v[a]++;
        vs[a].push_back(s);
    }
    std::vector<string> vsorted;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            vsorted.insert(vsorted.end(), vs[i].begin(), vs[i].end());
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i < n / 2)
            printf("- ");
        else
            cout << vsorted[i] << " ";
    }
    return 0;
}