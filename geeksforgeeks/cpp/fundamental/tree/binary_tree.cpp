#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left,* right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

Node* add(Node* root, int data) {
    if(root == nullptr) return new Node(data);
    if(data < root->data) root->left = add(root->left, data);
    else root->right = add(root->right, data);
    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << ' ';
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main() {
    vector<int> v = {50, 23, 63,12, 542, 654, 32,47,87, 54};
    Node* root = nullptr;
    for(int x: v) root = add(root, x);
    levelOrder(root);

    // cout << (1 << 3) - 1 << endl;
    return 0;
}