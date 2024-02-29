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
    void reverseDRHelper(Node * right,int floor){
        if(right==NULL){
            return;
        }
        reverseDRHelper(right->next,floor+1);
        if(floor>size/2){
            int temp = rLeft->data;
            rLeft->data=right->data;
            right->data=temp;
            rLeft=rLeft->next;
        }
    }
    Node * rLeft;
    void reverseDR(){
        rLeft=head;
        reverseDRHelper(head,0);
    }
};
int main(){
    LinkedList ll;
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(4);
    ll.addFirst(5);
    ll.addFirst(6);
    ll.display();
    ll.reverseDR();
    ll.display();
    return 0;
}