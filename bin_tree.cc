#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
    }
};

class BinaryTree{
private:
    Node* root;
public:
    BinaryTree(){
      root = nullptr;
    }
    bool empty(){
      return root == nullptr;
    }
    bool find(int data){
      Node* i = root;
      while (i != nullptr) {
        if (data == i->data){
            return true;
        }
        if (data < i->data){
          i = i->left;
        }
        else {
          i = i->right;
        }
      }
      return false;
    }

    void add(int data){
      if (root == nullptr){
        root = new Node(data);
      }
      else {
        Node* i = root;
        Node* parent_i = nullptr;
        while (i != nullptr) {
          parent_i = i;
          if (data < i->data){
            i = i->left;
          }
          else {
            i = i->right;
          }
        }
        if (data < parent_i->data){
          parent_i->left = new Node(data);
        }
        else{
          parent_i->right = new Node(data);
        }
      }
    }
    void remove(int data){
      cout << "remove "<< data << endl;
      if (root == nullptr){
        cout << "Tree is empty!" << endl;
        return;
      }
      Node* i = root;
      Node* parent_i = nullptr;
      while ((i != nullptr) && (i->data != data)) {
        parent_i = i;
        if (data < i->data){
          i = i->left;
        }
        else {
          i = i->right;
        }
      }
      cout << "skoncil som s while-om. Uz viem i." << endl;
      if (i == nullptr){
        cout << "Nenasiel som!" << endl;
        return;
      }
      if ((i->left == nullptr) || (i->right == nullptr)){
        cout << "iba jeden syn" << endl;
        Node* son = i->left;
        if (i->left == nullptr) {
          son = i->right;
        }
        if (parent_i == nullptr){
          root = son;
        }
        else if (i->data < parent_i->data){
          parent_i->left = son;
        }
        else {
          parent_i->right = son;
        }
        delete i;
      }
      else {
        cout << "dvaja synovia" << endl;
        Node* j = i->right;
        Node* parent_j = nullptr;
        while (j->left != nullptr){
          parent_j = j;
          j = j->left;
        }
        if (parent_j != nullptr) {
          parent_j->left = j->right;
          j->right = i->right;
        }
        j->left = i->left;
        if (parent_i == nullptr){
          root = j;
        }
        else if (i->data < parent_i->data){
          parent_i->left = j;
        }
        else {
          parent_i->right = j;
        }

        delete i;
      }
    }
  void removeSubtree(Node* n){
    if (n !=nullptr){
      removeSubtree(n->left);
      removeSubtree(n->right);
      delete n;
    }
  }

  ~BinaryTree(){
    removeSubtree(root);
  }

  void preorder(Node* n){
    if (n != nullptr){
      cout << n->data << endl;
      preorder(n->left);
      preorder(n->right);
    }
  }

  void preorder(){
    preorder(root);
    cout << endl;
  }

  void inorder(Node* n, int depth){
    if (n != nullptr){
      inorder(n->left, depth + 1);
      for (int i = 0; i<depth; i++){
        cout << "   ";
      }
      cout << n->data << endl;
      inorder(n->right, depth + 1);
    }
  }

  void inorder(){
    inorder(root, 0);
    cout << endl;
  }
};



int main(){
  cout << "hello world!" << endl;
  BinaryTree tree;
  tree.add(8);
  tree.add(4);
  tree.add(12);
  tree.add(2);
  tree.add(6);
  tree.add(10);
  tree.add(14);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  tree.add(9);
  tree.add(11);
  tree.add(13);
  tree.add(15);
  tree.preorder();
  tree.remove(10);
  cout << tree.find(8) << endl;
  cout << tree.find(4) << endl;
  cout << tree.find(12) << endl;
  cout << tree.find(11) << endl;
  tree.inorder();
  return 0;
}
