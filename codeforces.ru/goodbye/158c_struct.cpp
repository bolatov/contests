#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    string name;
    Node *parent;
    map<string, Node *> children;

    // Node() : parent(0) { ; }
    Node() { parent = 0; }
};

void printPath(Node *node) {
    stack<string> st;
    while (node->parent != 0) {
        st.push(node->name);
        node = node->parent;
    }
    while (!st.empty()) {
        cout << "/" << st.top();
        st.pop();
    }
    cout << "/" << endl;
}

Node *getRoot(Node *node) {
    while (node->parent != 0) {
        node = node->parent;
    }
    return node;
}

vector<string> getTokens(string &param) {
    vector<string> tokens;
    string token = "";
    for (int j = 0; j < (int)param.size(); ++j) {
        if (param[j] != '/')
            token += param[j];
        else {
            tokens.push_back(token);
            token = "";
        }

        if (j == (int)param.size() - 1)
            tokens.push_back(token);
    }
    return tokens;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string cmd, param;
    Node *node = new Node;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "pwd") {
            // print current dir
            printPath(node);
        } else {
            cin >> param;
            // go to $param dir
            if (param[0] == '/') {
                param.erase(param.begin());
                node = getRoot(node);
            }
            for (auto &dir : getTokens(param)) {
                if (dir == "..")
                    node = node->parent;
                else {
                    if (node->children.find(dir) != node->children.end()) {
                        node = node->children[dir];
                    } else {
                        Node *child = new Node;
                        child->parent = node;
                        child->name = dir;
                        node->children[dir] = child;
                        node = child;
                    }
                }
            }
        }
    }

    return 0;
}