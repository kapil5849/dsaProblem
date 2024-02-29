#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data = 0;
    Node * next = NULL;
    Node(int data){
        this->data=data;
    }
};
class LinkedList{
    public:
    Node * head = NULL;
    Node * tail = NULL;
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
    Node * getAtNode(int index){
        Node * current = this->head;
        while(index){
            current=current->next;
            index--;
        }
        return current;
    }
    int getAt(int index){
        if(index<0 or index>=this->size){
            return -1;
        }
        Node * node = getAtNode(index);
        return node->data;
    }
    void reverse_di(){
        int l =0;
        int r = this->size-1;
        while(l<r){
            Node * left = getAtNode(l);
            Node * right = getAtNode(r);
            int temp = left->data;
            left->data=right->data;
            right->data=temp;
            l++;
            r--;
        }
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
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(4);
    ll.addFirst(5);
    ll.display();
    ll.reverse_di();
    ll.display();
    return 0;
}