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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, M, a,b;
    cin >> N >> M;

    vector< set<int> > bag;
    set<int>::iterator it;
    VB u(N+1,false);
    REP(i,M) {
        cin >> a >> b;
        u[a]=true;
        u[b]=true;
        bool exist = false;
        REP(j,SZ(bag)) {
            set<int> s = bag[j];
            for(it=s.begin(); it!=s.end();++it) {
                if(s.find(a) != s.end() || s.find(b) != s.end()) {
                    exist = true;
                    s.insert(a);
                    s.insert(b);
                    bag[j] = s;
                    break;
                }
            }
        }
        if(!exist) {
            set<int> s;
            s.insert(a);
            s.insert(b);
            bag.PB(s);
        }
    }

    int maxSize=0, two=0,single=0;
    REP(i,SZ(bag)) {
        if (SZ(bag[i]) == 2) two++;
        maxSize = max(SZ(bag[i]),maxSize);
    }

    FOR(i,1,SZ(u)-1) {
        if (!u[i]) single++;
    }

    if ((two>0 && two>single) || maxSize>3) {
        cout << "-1" << endl;

//        //test
//        if (maxSize>3) cout << "maxSize=" << maxSize<<endl;
//        else cout << "two: " << two<< ", single: " << single << endl;
//        //end test

        return 0;
    }

    REP(i,SZ(bag)) {
        set<int> s = bag[i];
        for(it=s.begin(); it!=s.end();++it) {
            printf("%d ", *it);
        }

        REP(j,3-SZ(s)) {
            FOR(k,1,SZ(u)-1) {
                if (!u[k]) {
                    u[k] = true;
                    printf("%d ", k);
                    break;
                }
            }
        }
        printf("\n");
    }

    int cnt = 0;
    FOR(i,1,SZ(u)-1) {
        if (!u[i]) {
            cnt++;
            printf("%d ", i);
            if (cnt==3) {
                cnt=0;
                printf("\n");
            }
        }
    }

    return 0;
}

