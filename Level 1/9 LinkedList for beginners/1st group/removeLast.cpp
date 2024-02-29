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

    // size function 
    int sizeFun(){
        return this->size;
    }

    // check list is empty or not 
    bool isEmpty(){
        return this->size==0;
    }

    // add first in linked list
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

    Node * removeLastNode(){
        Node * node = this->tail;
        if(this->size==1){
            this->head=NULL;
            this->tail=NULL;
        }else{
            Node * current = head;
            while(current->next->next!=NULL){
                current=current->next;
            }
            delete current->next;
            current->next=NULL;
        }
        this->size--;
        return node;
    }

    int removeLast(){
        if(this->size==0){
            return -1;
        }
        Node * node = removeLastNode();
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
    ll.removeLast();
    ll.display();
    return 0;
}