#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
private:

public:
    int data;
    Node* next;
    Node(int data, Node* next) : this->data(data), this->next(next) {
    }

};

class LinkedList{
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {
    }

    LinkedList(Node* root) : this->root(root) {
    }

    void setRoot(Node* root){
      this->root = root;
    }
    bool empty(){
      return root == nullptr;
    }
    void addFront(int data){
      Node* v = new Node(data, root);
      root = v;
    }
    int remove(){
      int d = root->data;
      Node* old_root = root;
      root = root->next;
      delete old_root;
      return d;
    }

    void print(){
      Node* i = root;
      while (i != nullptr) {
        cout << i->data << endl;
        i = i->next;
      }
      cout <<endl;
    }

    ~LinkedList(){
      while (!empty()) {
        remove();
      }
    }

    void reverse(){
      if (root != null) {
        return;
      }
      Node* i = root;
      Node* reverse_root = nullptr;
      while (i->next != nullptr) {
        Node* j = i->next;
        i->next = reverse_root;
        reverse_root = i;
        i = j;
      }
      root = reverse_root;
    }

  //   bool cycle(){
  //     Node* a = root;
  //     Node* b = root;
  //     while ((a != b) & (a != nullptr) & (b != nullptr)) {
  //       a = a->getNext();
  //       b = (b->getNext())->getNext;
  //   }
  //   if ((a == nullptr) | (b == nullptr)) {
  //     return false;
  //   } else {
  //     return true;
  //   }
  // }
  //
  // int len(){
  //   int N = 0;
  //   Node* i = root;
  //   while (i != nullptr) {
  //     N++;
  //     i = i->getNext();
  //   }
  //   return N;
  // }

};

//
// class Stack zdedena z LinkedList{
//
// private:
//   maxlist LinkedList;
// public:
//     Stack() {
//       root = nullptr;
//       maxlist = ...?;
//     }
//   void push(int data) {
//     self.addFront(int data)
//     maxlist.addFront(max(maxlist.root->getData(), data))
//   }
//
//   void pop() {
//     self.setRoot(root->getNext())
//     maxlist.root.setRoot(root->getNext())
//     //vymazat vrcholy?
//   }
//
//   int top() {
//     return root->getData()
//   }
//
//   int max() {
//     return maxlist.root->getData()
//   }
//
// void
//
// void quickSort(LinkedList list) {
//    int N = list.len();
//    srand (time(NULL));
//    pivot = rand() % N + 1;
//    root1 = root;
//    root2 = pivot->getNext();
//    pivot->setNext(nullptr);
//    list1 = new LinkedList(root1);
//    list2 = new LinkedList(root2);
//    quickSort(list1);
//    quickSort(list2);
//    Node* i = list1.root1;
//    while (i->getNext() != nullptr) {
//      i = i->getNext();
//    }
//    i->setNext(root2);
//    list.setRoot(root1);
// }

int main(){
    cout << "Hello World!" << endl;
    LinkedList list;
    list.addFront(1);
    list.print();
    list.addFront(2);
    list.print();
    list.remove();
    list.print();
    list.addFront(3);
    list.print();
    list.reverse();
    //cout << list.cycle();
    list.print();
    return 0;
}
