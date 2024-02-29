#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data = 0;
    Node* next = NULL;
    Node(int data){
        this->data = data;
    }
};
class LinkedList{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    void addFirstNode(Node *node){
        if(this->size==0){
            this->head=node;
            this->tail=node;
        }else{
            node->next=this->head;
            this->head=node;
        }
        this->size++;
    }
    void addFirst(int val){
        Node * node = new Node(val);
        addFirstNode(node);
    }

    Node * removeFirstNode(){
        Node * node = this->head;
        if(this->size==1){
            this->head=NULL;
            this->tail=NULL;
        }else{
            this->head=this->head->next;
            node->next=NULL;
        }
        this->size--;
        return node;
    }
    int removeFirst(){
        if(this->size==0){
            return -1;
        }
        Node * node = removeFirstNode();
        int value = node->data;
        delete node;
        return value;
    }

    // display a linked list
    void display(){
        for(Node * node=head;node!=NULL;node=node->next){
            cout<<node->data<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(4);
    ll.addFirst(5);
    ll.display();
    ll.removeFirst();
    ll.display();
    return 0;
}