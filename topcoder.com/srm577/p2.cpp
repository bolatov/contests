#include <set>
#include <map>
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

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

typedef list<int>       LI;

const double EPS = 10e-9;
const double INF = (1LL << 30);

using namespace std;

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

// Problem 500
class EllysRoomAssignmentsDiv2 {
public:
    double getProbability(vector <string> r) {
        VI rs;
        bool isElly = true;
        int num, ielly;

        string longString = "";
        REP(i, SZ(r)) {
            longString += r[i];
        }

        string s;
        istringstream iss(longString);
        while(getline(iss,s,' ')) {
            num = str2int(s.c_str());
            if (isElly) {
                isElly = false;
                ielly = num;
            }
            rs.PB(num);
        }

        int N =SZ(rs);
        int R = (N%20==0) ? N/20 : N/20 + 1;
//        printf("ielly = %d\n", ielly);
        printf("Competitors = %d\n", N);
        printf("R=%d\n", R);

        SORT(rs);
        int ellyPos=0;
        FORD(i,SZ(rs)-1, 0) {
//            printf("%d\n", rs[i]);
            if (rs[i] == ielly) {
                break;
            }
            ellyPos++;
        }

        ellyPos++;
        printf("ellyPos = %d\n", ellyPos);

        double res = 0;
        if (R == 1 || ellyPos == 1) {
            res = 1;
        } else if (ellyPos <= R) {
            res = 0;
        } else {
            res = 1/(double)R;
        }

        return res;
    }
};

int main() {
    freopen("output.txt", "w", stdout);

    EllysRoomAssignmentsDiv2 sp;
    VS rs = {"1197 182 958 625 624 370 1178 952 823 340 663 686 ", "1189 244 503 790 814 451 656 551 452 740 188 996 3", "33 1132 1053 935 687 326 612 969 1034 832 263 816 ", "925 682 571 541 725 165 597 729 207 224 161 619 47", "8 237 598 1119 766 605 874 228 264 432 246 674 21 ", "751 202 931 174 311 951 444 702 770 971 1141 1091 ", "860 19 168 418 997 700 634 689 283 882 817 521 100", "6 26 977 399 601 258 230 235 477 567 23 1021 557 3", "4 319 328 77 810 1142 37 295 1045 209 1058 390 4 2", "51 39 408 726 805 63 9 104 778 758 583 532 17 420 ", "1171 179 978 442 1195 1183 111 851 980 668 513 110", "4 73 459 466 856 303 45 1122 474 694 752 909 1145 ", "948 514 29 1159 515 27 360 910 627 1179 272 482 59", "1 445 638 50 108 924 695 191 256 1191 448 262 609 ", "1165 248 718 715 1148 382 327 424 872 569 904 94 5", "28 743 1030 206 995 840 387 572 267 456 539 231 13", "8 529 819 650 1153 310 43 1188 281 329 473 942 429", " 494 547 1074 426 1061 821 479 696 999 748 699 116", "4 1033 449 658 1000 292 226 64 803 491 864 815 708", " 223 158 1180 1196 197 7 1131 375 1060 545 180 993", " 781 30 984 1031 371 1073 861 834 1092 476 818 112", " 185 692 240 745 930 828 350"}
            ;


    cout << sp.getProbability(rs) << endl;
    return 0;
}
