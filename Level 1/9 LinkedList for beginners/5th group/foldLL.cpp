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
        }
        else{
            node->next=this->head;
            this->head=node;
        }
        this->size++;
    }
    void addFirst(int val){
        Node * node= new Node(val);
        addFirstNode(node);
    }
    void display(){
        for(Node * node=head;node!=NULL;node=node->next){
            cout<<node->data<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
    Node * left;
    void foldHelper(Node * right, int floor){
        if(right==NULL){
            return;
        }
        foldHelper(right->next,floor+1);
        if(floor>this->size/2){
            Node * temp = left->next;
            left->next=right;
            right->next=temp;
            left=temp;
        }else if(floor==this->size/2){
            this->tail=right;
            tail->next=NULL;
        }
    }
    void fold(){
        left=head;
        foldHelper(this->head,0);
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
    ll.fold();
    ll.display();
    return 0;
}