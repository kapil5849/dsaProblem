#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data = 0;
    Node * next = NULL;
    Node(int data){
        this->data = data;
    }
};
class LinkedList{
    public:
    Node * head = NULL;
    Node * tail = NULL;
    int size = 0;
    void addLastNode(Node * node){
        if(this->size==0){
            this->head=node;
            this->tail=node;
        }else{
            this->tail->next=node;
            this->tail = node;
        }
        this->size++;
    }
    void addLast(int val){
        Node * node = new Node(val);
        addLastNode(node);
    }
    void display(){
        for(Node * node=head;node!=NULL;node=node->next){
            cout<<node->data<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList ll;
    ll.addLast(1);
    ll.addLast(2);
    ll.addLast(3);
    ll.addLast(4);
    ll.addLast(5);
    ll.display();
    return 0;
}