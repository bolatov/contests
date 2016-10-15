#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> v;
    string t = "";
    for (char ch : s) {
        if (ch == delimiter) {
            if (!t.empty()) {
                v.push_back(t);
                t = "";
            }
        } else {
            t += ch;
        }
    }
    if (!t.empty()) {
        v.push_back(t);
    }
    return v;
}

string smartSubstring(string s, int len) {
    if ((int)s.size() <= len) {
        return s;
    }
    vector<string> tokens = split(s, ' ');
    string t = "";
    for (string token : tokens) {
        if ((int)t.size() + (int)token.size() + 1 > len) {
            break;
        }
        if (!t.empty()) {
            t += " ";
        }
        t += token;
    }
    return t;
}

int main() {
    string s =
        "Featuring stylish rooms and moornings for recreation boats, Room Mate Aitana is a "
        "designer hotel built in 2013 on an island in the IJ River in Amsterdam.";
    cout << "'" << smartSubstring(s, 30) << "'" << endl;
    return 0;
}