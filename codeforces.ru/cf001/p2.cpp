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
#include <stdexcept>
using namespace std;

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

std::string int2str( int n )
{
    std::ostringstream result;
    result << n;
    return result.str();
}

int str2int( const std::string& s )
{
    int result;
    std::istringstream ss( s );
    ss >> result;
    if (!ss) throw std::invalid_argument( "StrToInt" );
    return result;
}

int getNumber(vector<char> seq) {
    int num = 0;
    while (seq.size() > 0) {
        bool changed = false;
        for (int i = seq.size()-1; i >= 0; i--) {
            if (seq[i] > 'A') {
                seq[i]--;
                changed = true;
                num++;
                break;
            } else if (seq[i] == 'A') {
                seq[i] = 'Z';
            }
        }

        if (!changed) {
            vector<char> copy;//('A', seq.size()+1);
            REP(k, seq.size()-1) {
                copy.push_back('Z');
            }
            seq = copy;
            num++;
        }
    }
    return num;
}

string getLetters(int num) {
    vector<char> seq = {'A'};
    REP(j, num-1) {
        bool changed = false;
        for (int i = seq.size()-1; i >= 0; i--) {
            if (seq[i] < 'Z') {
                seq[i]++;
                changed = true;
                break;
            } else if (seq[i] == 'Z') {
                seq[i] = 'A';
            }
        }

        if (!changed) {
            vector<char> copy;//('A', seq.size()+1);
            REP(k, seq.size()+1) {
                copy.push_back('A');
            }
            seq = copy;
        }
    }
    string res = "";
    for (int i = 0; i < seq.size(); i++) {
        // cout << seq[i];
        res += seq[i];
    }
    // cout << endl;
    return string(res);
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    REP(i, N) {
        string str;
        cin >> str;
        string res = "";
        if (str[0] == 'R') {
            int ind = str.find_last_of('C');
            int row = str2int(str.substr(ind+1));
            res += getLetters(row);
            res += str.substr(1, ind-1);
            cout << res << endl;
        } else {
            int ind = 0;
            vector<char> seq;
            while (ind < str.length()) {
                if (str[ind] >= 'A' && str[ind] <= 'Z')
                    seq.push_back(str[ind]);
                else break;
                ind++;
            }
            res += 'R';
            res += str.substr(ind);
            res += 'C';
            res += int2str(getNumber(seq));
            cout << res << endl;
        }
    }

    return 0;
}
