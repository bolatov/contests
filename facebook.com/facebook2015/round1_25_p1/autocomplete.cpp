#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map<char, Node *> edges;
};

int lcp(Node *node, string s) {
    int ilcp = 0;
    for (char ch : s) {
        if (node->edges.find(ch) == node->edges.end()) {
            break;
        }
        node = node->edges[ch];
        ilcp++;
    }
    return ilcp;
}

void add(Node *node, string s) {
    for (char ch : s) {
        if (node->edges.find(ch) == node->edges.end()) {
            Node *child = new Node;
            node->edges[ch] = child;
        }
        node = node->edges[ch];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int itest = 1; itest <= t; ++itest) {
        int n, ans = 0;
        Node *node = new Node;
        cin >> n;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            int ilcp = lcp(node, s);
            ans += ilcp + (ilcp != (int)s.size());
            add(node, s);
        }
        printf("Case #%d: %d\n", itest, ans);
        node = 0;
    }
    return 0;
}