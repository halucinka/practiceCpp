#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Node{
private:

public:
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) {
    }

};

class LinkedList{
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {
    }

    LinkedList(Node* root) : root(root) {
    }


    Node* getRoot(){
      return root;
    }

    bool empty() const {
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

    void print() const{
      print(root);
    }

    ~LinkedList(){
      while (!empty()) {
        remove();
      }
    }

    void reverse(){
      if (root == nullptr) {
        return;
      }
      Node* i = root;
      Node* reverse_root = nullptr;
      while (i != nullptr) {
        Node* j = i->next;
        i->next = reverse_root;
        reverse_root = i;
        i = j;
      }
      root = reverse_root;
    }

    bool cycle() const{
      if (root == nullptr) {
        return false;
      }
      Node* a = root;
      Node* b = root->next;
      while ((a != b) && (a != nullptr) && (b != nullptr) && (b->next != nullptr)) {
        a = a->next;
        b = b->next->next;
    }
    if ((a == nullptr) || (b == nullptr) || (b->next == nullptr)) {
      return false;
    } else {
      return true;
    }
  }

  int len() const {
    int N = 0;
    Node* i = root;
    while (i != nullptr) {
      N++;
      i = i->next;
    }
    return N;
  }

  void quickSort() {
    root = quickSort(this->root, this->len());
  }

  static Node* quickSort(Node* root, int N) {
     if (N <= 1) {
       return root;
     }
     srand(time(NULL));
     const int num_pivot = rand() % N;
     Node* pivot = root;
     for (int i = 0; i < num_pivot; i++) {
       pivot = pivot->next;
     }
     const int pivot_data = pivot->data;
     Node* i = root;
     Node* root1 = nullptr;
     Node* root2 = nullptr;
     int N1 = 0;
     int N2 = 0;
     while (i != nullptr) {
       Node* j = i->next;
       if (i->data < pivot_data){
         N1++;
         i->next = root1;
         root1 = i;
       } else {
         N2++;
         i->next = root2;
         root2 = i;
       }
       i = j;
     }
     root1 = quickSort(root1, N1);
     root2 = quickSort(root2, N2);
     if (root1 == nullptr) {
       return root2;
     }
     if (root2 == nullptr) {
       return root1;
     }
     Node* k = root1;
     while (k->next != nullptr) {
       k = k->next;
     }
     k->next = root2;
     return root1;
  }

  static void print(Node* root){
    //cout << "print" << endl;
    Node* i = root;
    while (i != nullptr) {
      cout << i->data << endl;
      i = i->next;
    }
    //cout <<"-----------"<< endl;
  }


  void mergeSort() {
    root = mergeSort(this->root, this->len());
  }

  static Node* mergeSort(Node* root, int N) {
    //cout << "mergesort " << N << endl;
    if (N <= 1) {
      return root;
    }
    int num_pivot = (N-1)/2;
    Node* pivot = root;
    for (int i = 0; i < num_pivot; i++) {
      pivot = pivot->next;
    }
    Node* root1 = root;
    Node* root2 = pivot->next;
    pivot->next = nullptr;
    int N1 = num_pivot + 1;
    int N2 = N - num_pivot - 1;
    root1 = mergeSort(root1, N1);
    root2 = mergeSort(root2, N2);
    //cout << "po zotriedeni polovic " << N1 << " " << N2 << endl;
    //cout << "root1" << endl;
    //cout << "root2" <<endl;

    if (root1->data < root2->data) {
      root = root1;
      root1 = root1->next;
    } else {
      root = root2;
      root2 = root2->next;
    }


    
    Node* temp = root;
    //cout << "pred while " << N1 << " " << N2 << endl;
    while ((root1 != nullptr) && (root2 != nullptr)) {
      //cout << "vo while " << N1 << " " << N2 << endl;
      if (root1->data < root2->data) {
        temp->next = root1;
        root1 = root1->next;
      } else {
        temp->next = root2;
        root2 = root2->next;
      }
      temp = temp->next;
    }
    if (root1 != nullptr) {
      temp->next = root1;
    } else {
      temp->next = root2;
    }
    //cout << "printujem zotriedene "<< N1 << " " << N2 << endl;
    return root;
  }
};


class Stack {

private:
    LinkedList stack;
    LinkedList maxlist;
public:
    Stack() : stack(), maxlist() {
    }

    void push(int data) {
      stack.addFront(data);
      if (maxlist.getRoot() == nullptr) {
          maxlist.addFront(data);
      } else {
        maxlist.addFront(std::max(maxlist.getRoot()->data, data));
      }
    }

    int pop() {
      maxlist.remove();
      return stack.remove();
    }

    int top() {
      return stack.getRoot()->data;
    }

    int max() {
      return maxlist.getRoot()->data;
    }
};


int main(){
    cout << "Hello World!" << endl;
    LinkedList list;
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.print();
    cout << "Dlzka: " << list.len() << endl;
    cout << "sortime: " << endl;
    list.mergeSort();
    list.print();
    // Stack s;
    // s.push(1);
    // s.push(47);
    // s.push(2);
    // s.pop();
    // //cout <<"top " << s.top() << endl;
    // //cout <<"max " << s.max() << endl;


    ////cout << "print reverse:" << endl;
    //list.print();
    return 0;
}
