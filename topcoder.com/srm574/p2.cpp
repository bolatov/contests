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

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

// Problem 500
class TheNumberGameDiv2 {
    public:
    int minimumMoves(int A, int B) {
        string astr = int2str(A);
        string bstr = int2str(B);

        if (astr.size() < bstr.size())  return -1;
        
        if (astr.find(bstr) == string::npos && astr.find(getRev(bstr)) == string::npos) {
            return -1;
        }

        int res = -1;
        if (astr.find(bstr) != string::npos) {
            int index = astr.find(bstr);
            int v = index > 0 ? 2 : 0;
            v += index + (astr.size()-(index+bstr.size()));
            res = v;
        }
        printf("1: %d\n", res);
        
        string arev = getRev(astr);
        if (arev.find(bstr) != string::npos) {
            int index = arev.find(bstr);
            int v = index > 0 ? 1 : 0;
            v += index + (arev.size()-(index+bstr.size()));
            if (res != -1) {
                res = min(res,v);
            } else
                res = v;
        }
        printf("2: %d\n", res);

        return res;
    }
    private:
    std::string int2str( int n ) {
        std::ostringstream result;
        result << n;
        return result.str();
    }

    string getRev(string str) {
        string res = "";
        for (int i = str.size()-1; i >= 0; i--) {
            res += str[i];
        }
        return res;
    }
};

int main() {
    TheNumberGameDiv2 sm;
    printf("result=%d\n", sm.minimumMoves(25, 5));
    // printf("result=%d\n", sm.minimumMoves(218181918, 9181));
    return 0;
}