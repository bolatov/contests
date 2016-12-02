#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int volumeThickness, coverThickness, startVolume, endVolume;
    cin >> volumeThickness >> coverThickness >> startVolume >> endVolume;

    // // number of books
    int books = max(startVolume - endVolume, endVolume - startVolume) + 1;

    // // thickness of a single book
    int bookThickness = volumeThickness + 2 * coverThickness;

    // // total thickness of the path
    int totalThickness = books * bookThickness;

    // // remove two covers
    totalThickness -= 2 * coverThickness;

    // // possibly remove 2 volume

    if (startVolume == endVolume) {
        cout << volumeThickness << endl;
        return 0;
    }

    if (startVolume < endVolume) {
        totalThickness -= 2 * volumeThickness;
    }

    cout << totalThickness << endl;

    return 0;
}