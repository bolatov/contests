#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector<int> ar, int ar_size) {
    int cnt = 0;
    for (int i = 1; i < ar_size; ++i) {
        int ind = i;
        for (int j = i - 1; j >= 0; --j) {
            if (ar[j] > ar[ind]) {
                int t = ar[ind];
                ar[ind] = ar[j];
                ar[j] = t;
                ind--;
                cnt++;
            }
        }
    }
    // cout << cnt << endl;
    return cnt;
}

void quickSort(std::vector<int> &v, int l, int r, int &cnt) {
    if (l >= r - 1)
        return;

    int p = r - 1;
    int index = l;
    for (int i = l; i < p; ++i) {
        if (v[i] < v[p]) {
            int t = v[i];
            v[i] = v[index];
            v[index] = t;
            index++;

            cnt++;
        }
    }
    int t = v[index];
    v[index] = v[p];
    v[p] = t;
    p = index;
    cnt++;

    quickSort(v, l, p, cnt);
    quickSort(v, p + 1, r, cnt);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int isort = insertionSort(v, n);
    int cnt = 0;
    quickSort(v, 0, n, cnt);
    // printf("cnt1=%d, cnt2=%d\n", isort, cnt);
    cout << isort - cnt;
    return 0;
}