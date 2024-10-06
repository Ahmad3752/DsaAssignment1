#include<iostream>
using namespace std ;
#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include <cmath>

class Node {
public:
   uint64_t value; 
    Node* next;

    Node(int value) {
        this->value=value;
        this->next=nullptr;
    }

    ~Node() {
        cout << "Successfully deleted " << endl;
    }
};
void append(Node* &tail,int d){
  Node * temp =new Node(d);
  tail->next=temp;
  temp=tail;
}
void print(Node * head){
  cout<<"the number is "<<endl;
  while(head!=nullptr){
    cout<<head->value;
    head=head->next;
  }
}
int main(){

    Node *node1 =new Node(1234567890123456789ULL);
    Node * head=node1;
    Node * tail=node1;
    append(tail,9876543210987654321ULL);  // Chunk 2
    append(tail,1234567890123456789ULL);  // Chunk 3
 append(tail,9876543210987654321ULL);  // Chunk 4
    print(head);

return 0;
}