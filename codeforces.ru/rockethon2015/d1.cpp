#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *parent;
    Node *left;
    Node *right;
    // Node() { /*parent = */
    // left = right = 0;
    // }
    Node(int v) {
        value = v;
        parent = left = right = 0;
    }
};

void visit(Node *node) {
    if (node->left != 0) {
        visit(node->left);
    }
    printf("%d ", node->value);
    if (node->right != 0) {
        visit(node->right);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, c;
    cin >> n >> c;
    // map<int, Node *> mp;
    vector<Node *> mp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        mp[i] = new Node(i);
    }
    int a, b;
    string s;
    vector<int> vb(n + 1, 0);
    for (int i = 0; i < c; ++i) {
        cin >> a >> b >> s;
        Node *node = mp[a];
        Node *child = mp[b];
        if (s[0] == 'L') {
            node->left = child;
        } else {
            node->right = child;
        }
        vb[a]++;
        if (vb[a] > 2) {
            puts("IMPOSSIBLE");
            return 0;
        }
        child->parent = node;
    }

    int last = 1;
    for (int i = 2; i <= n; ++i) {
        Node *node = mp[i];
        if (node->parent == 0) {
            for (int j = last; j <= n; ++j) {
                if (vb[j] < 2) {
                    if (mp[j]->left == 0) {
                        mp[j]->left = node;
                    } else {
                        mp[j]->right = node;
                    }
                    vb[j]++;
                    if (vb[j] == 2) {
                        last++;
                    }
                    break;
                }
            }
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
        Node *node = mp[i];
        Node *l = node->left;
        Node *r = node->right;
        if (l != 0 && r != 0 && l->value > r->value) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        visit(mp[1]);
        cout << endl;
    } else {
        puts("IMPOSSIBLE");
    }

    return 0;
}