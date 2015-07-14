#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    /* SOLUTION 1 */
//    int k = 0;
//    for (int i = 0; i < N; ++i) {
//        printf("%d ", 3*N+k);
//        k++;
//    }
//    printf("\n");

    /* SOLUTION 2 */
    list<int> ps;
    for (int i = 2; i < 1e7; i++) {
        ps.push_back(i);
    }
    int i = 0;
    for (list<int>::iterator it1 = ps.begin(); it1 != ps.end(); ++it1) {
        if (i == N)
            break;
        printf("%d ", *it1);
        list<int>::iterator it2 = it1;
        it2++;
        while (it2 != ps.end()) {
            if (*it2 % *it1 == 0) {
                it2 = ps.erase(it2);
            } else {
                *it2++;
            }
        }
        i++;
    }
//    list<int>::iterator it = ps.begin();
//    while (N--) {
//        printf("%d ", *it);
//        ++it;
//    }
    printf("\n");
}
