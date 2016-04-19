#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int data, Node* next){
      this->data = data;
      this->next = next;
    }
    int getData(){
      return data;
    }
    Node* getNext(){
      return next;
    }
};

class LinkedList{
private:
    Node* root;
public:
    LinkedList() {
      root = nullptr;
    }
    bool empty(){
      return root == nullptr;
    }
    void add(int data){
      Node* v = new Node(data, root);
      root = v;
    }
    int remove(){
      int d = root->getData();
      Node* old_root = root;
      root = root->getNext();
      delete old_root;
      return d;
    }

    void print(){
      Node* i = root;
      while (i != nullptr) {
        cout << i->getData() << endl;
        i = i->getNext();
      }
      cout <<endl;
    }

    ~LinkedList(){
      while (!empty()) {
        remove();
      }
    }

};

int main(){
    cout << "Hello World!" << endl;
    LinkedList list;
    list.add(1);
    list.print();
    list.add(2);
    list.print();
    list.remove();
    list.print();
    list.add(3);
    list.print();

    return 0;
}
