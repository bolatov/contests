#include <bits/stdc++.h>
using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int currId = 1;
struct Node {
    bool used;
    Node *left;
    Node *right;
    Node *parent;
    int height;
    int id;
    Node() { used = 0, left = 0, right = 0, parent = 0, height = 0, id = -1; }
};

bool isLeaf(Node *node) { return node->left == 0 && node.right == 0; }

void createTree(Node *root, int h) {
    if (root->height == h) {
        root->id = currId;
        currId++;

    } else {
        // left
        Node *lnode = new Node();
        lnode->parent = root;
        lnode->height = root->height + 1;
        createTree(lnode, h);

        // right
        Node *rnode = new Node();
        rnode->parent = root;
        rnode->height = root->height + 1;
        createTree(rnode, h);
    }
}

void solve(Node *node, int id, set<int> &vs, bool isLeft) {
    if (isLeaf(node)) {
        if (node->id == id)
            return;
        solve(node->parent, id, vs, !isLeft);
    }

    if (nd->left.used && nd->right.used) {
        nd = nd->parent;
    }

    if (isLeft && !nd->left.used) {
        nd->left.used = 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int h, n;
    scanf("%d %d", &h, &n);

    Node *node = new Node();
    createTree(node, h);
    set<int> vs;
    solve(node, n, vs, 1);
    printf("%d\n", (int)vs.size());
    return 0;
}