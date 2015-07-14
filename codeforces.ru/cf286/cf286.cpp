#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

struct Node {
    Node *a;
    Node *b;
    Node *c;
    Node() { a = b = c = 0; }
};

bool isLeaf(Node *node) { return node->a == 0 && node->b == 0 && node->c == 0; }

bool check(Node *node, string s, int d) {
    cout << s << " " << d << endl;
    if (s == "") {
        return isLeaf(node) ? 1 : 0;
    }
    if (isLeaf(node)) {
        return 0;
    }
    cout << node->a << endl;
    bool ach = ((d > 0 || s[0] == 'a') && node->a != 0)
                   ? check(node->a, s.substr(1), d - (s[0] != 'a'))
                   : 0;
    // bool bch = ((d > 0 || s[0] == 'b') && node->b != 0)
    //                ? check(node->b, s.substr(1), d - (s[0] != 'b'))
    //                : 0;
    // bool cch = ((d > 0 || s[0] == 'c') && node->c != 0)
    //                ? check(node->c, s.substr(1), d - (s[0] != 'c'))
    //                : 0;
    // return ach || bch || cch;
    return ach;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    Node *root = new Node();
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        Node *node = root;
        for (char ch : s) {
            if (ch == 'a') {
                node->a = new Node();
                node = node->a;
            } else if (ch == 'b') {
                node->b = new Node();
                node = node->b;
            } else {
                node->c = new Node();
                node = node->c;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        puts(check(root, s, 1) ? "YES" : "NO");
    }
    return 0;
}
