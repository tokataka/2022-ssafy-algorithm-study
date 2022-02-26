// https://www.acmicpc.net/problem/1991

#include <iostream>
using namespace std;

struct Node {
  char name;
  Node* left;
  Node* right;
};

Node* root = new Node{'A', 0, 0};

Node* find_node(Node* node, char name) {
  if (!node) return 0;
  if (node->name == name) return node;

  Node* cur = find_node(node->left, name);
  if (cur) return cur;

  cur = find_node(node->right, name);
  if (cur) return cur;

  return 0;
}

void print_node_pre(Node* node) {
  if (!node) return;

  cout << node->name;
  print_node_pre(node->left);
  print_node_pre(node->right);
}

void print_node_in(Node* node) {
  if (!node) return;

  print_node_in(node->left);
  cout << node->name;
  print_node_in(node->right);
}

void print_node_post(Node* node) {
  if (!node) return;

  print_node_post(node->left);
  print_node_post(node->right);
  cout << node->name;
}

int main(void) {
  int n;
  cin >> n;

  Node* root = new Node{'A', 0, 0};
  for (int i = 0; i < n; i++) {
    char a[3];
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }

    Node* node = find_node(root, a[0]);
    if (a[1] != '.') node->left = new Node{a[1], 0, 0};
    if (a[2] != '.') node->right = new Node{a[2], 0, 0};
  }

  print_node_pre(root);
  cout << '\n';
  print_node_in(root);
  cout << '\n';
  print_node_post(root);
  cout << '\n';

  return 0;
}
