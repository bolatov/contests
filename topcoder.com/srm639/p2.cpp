#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

class AliceGameEasy {
public:
    long long findMinimumValue(long long x, long long y) {
        long long sum = x + y;
        long long k = 0;
        for (long long i = 1; sum > 0; i++) {
            sum -= i;
            if (sum < 0) {
                return -1L;
            }
            k = i;
        }

        long long minVal = 0;
        for (; k > 0; k--) {
            if (x - k >= 0) {
                x -= k;
                minVal++;
            }

            if (minVal == 0) {
                break;
            }
        }

        return minVal;
    }
};

int main() {
    AliceGameEasy s;

    cout << s.findMinimumValue(100000,
                               400500) << endl;

    return 0;
}

