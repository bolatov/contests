#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef pair<int,string> PIS;
typedef vector<string> VS;
typedef vector<PIS> VPIS;

int h(string& key) {
    int sum = 0;
    for (size_t i = 0; i < key.size(); i++) {
        sum += key[i]*(i+1);
    }
    return sum*19;
}

int hsh(string& key) {
    return h(key) % 101;
}

int find(VS& table, string& key) {
    for (size_t i = 0; i < table.size(); ++i) {
        if (table[i] == key)
            return i;
    }
    return -1;
}

void add(VS&table, string& key) {
    if (find(table, key) >= 0) return;

    int index = hsh(key);
    bool isOpen = table[index] == "";
    if (isOpen)
        table[index] = key;
    else
       for (int j = 1; j <= 19; ++j) {
           int i = hsh(key) + j*j + 23*j;
           i %= 101;
           if (table[i] == "") {
               table[i] = key;
               break;
           }
       }
}

void delKey(VS& table, string& key) {
    int i = find(table, key);
    if (i >= 0) table[i] = "";
}

VPIS getValues(VS& table) {
    VPIS values;
    for (size_t i = 0; i < table.size(); ++i) {
        if (table[i] != "") {
            values.push_back(make_pair(i, table[i]));
        }
    }
    return values;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T,N;
    string cmd, str;
    cin >> T;
    while (T--) {
        cin >> N;
        VS table(102, "");
        for (int i = 0; i < N; ++i) {
            cin >> cmd;
            int j = cmd.find(":");
            str = cmd.substr(j+1);
            if (cmd.find("ADD") != string::npos) {
                add(table, str);
            } else {
                delKey(table, str);
            }
        }
        VPIS values = getValues(table);
        cout << values.size() << endl;
        for (size_t i = 0; i < values.size(); ++i) {
            cout << values[i].first << ":" << values[i].second << endl;
        }
    }

    return 0;
}
