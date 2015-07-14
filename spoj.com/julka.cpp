#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD(x, n) ((x)%(n)+(n))%(n)

typedef vector<int> VI;
typedef vector<VI>  VVI;

VI add(VI& a, VI& b) {
    VI res;
    int len = min(a.size(), b.size());
    int q = 0, s, i;
    for (i = 0; i < len; ++i) {
        s = a[i] + b[i] + q;
        q = s / 10;
        s = s % 10;
        res.push_back(s);
    }
    VI lvi = a.size() > b.size() ? a : b;
    len = lvi.size();
    for (; i < len; ++i) {
        s = lvi[i] + q;
        q = s / 10;
        s = s % 10;
        res.push_back(s);
    }
    if (q > 0) res.push_back(q);
    return res;
}

// subtract a-b
// assumes a > b
VI sub(VI& a, VI& b) {
    VI res;
    int len = min(a.size(), b.size());
    int q = 0, s, i;
    for (i = 0; i < len; i++) {
        a[i] -= q;
        q = 0;
        s = a[i] - b[i];
        if (s < 0) {
            s = MOD(s, 10);
            q = 1;
        }

        res.push_back(s);
    }

    for(; i<max(a.size(),b.size()); i++) {
        a[i] -= q;
        q = 0;
        s = a[i];
        if (s < 0) {
            s = MOD(s, 10);
            q = 1;
        }
        res.push_back(s);
    }

    while (res[res.size()-1] == 0) {
        res.pop_back();
    }
    return res;
}

VI div(VI& a, int d) {
    VI res;
    int ai=0, s=0;
    for (int i = a.size()-1; i >= 0; --i) {
        ai += a[i];
        if (ai < d) {
            ai *= 10;
            res.push_back(0);
            continue;
        }
        s = ai / d;
        ai = ai % d;
        ai *= 10;
        res.push_back(s);
    }
    reverse(res.begin(), res.end());
    while (res[res.size()-1]==0) {
        res.pop_back();
    }
    return res;
}

VI toVI(int n) {
    VI vi;
    while (n > 0) {
        vi.push_back(n%10);
        n /= 10;
    }
    return vi;
}

pair<VI, VI> solve(VI& sv, VI& dv) {
    pair<VI,VI> ans;
    VI svdv = sub(sv,dv);
    VI mv = div(svdv, 2);
    ans.first = add(mv, dv);
    ans.second = mv;
    return ans;
}

void prln(VI vi) {
    for (int i = vi.size()-1; i >= 0 ; --i) {
        printf("%d", vi[i]);
    }
    printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 10;
    for (int itest = 0; itest < T; ++itest)
    {
        VI nvi, dvi;
        string N, D;
        cin >> N >> D;
        for (int i = 0; i < N.size(); i++) {
            nvi.push_back(N[i]-'0');
        }
        for (int i = 0; i < D.size(); i++) {
            dvi.push_back(D[i]-'0');
        }
        reverse(nvi.begin(), nvi.end());
        reverse(dvi.begin(), dvi.end());
        pair<VI, VI> ans = solve(nvi,dvi);
        prln(ans.first);
        prln(ans.second);
    }

    return 0;
}


