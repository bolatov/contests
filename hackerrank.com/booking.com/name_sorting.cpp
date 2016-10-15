#include <bits/stdc++.h>

using namespace std;

/**
 * Given a list/array of names (String). Sort them such that each name
 * is followed by a name which starts with the last character of the previous
 * name.
 */
vector<string> bookingSort(vector<string> names) {
    for (string name : names) {
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        cout << name << endl;
    }

    return names;
}

int main() {
    vector<string> names = {"Luis", "Hector", "Selena", "Emmanuel", "Amish"};
    auto sorted = bookingSort(names);
    // for (string s : sorted) {
    // cout << s << endl;
    // }
    return 0;
}