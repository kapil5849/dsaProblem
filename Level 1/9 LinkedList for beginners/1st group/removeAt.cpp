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
    Node* removeFirstNode(){
        Node* node=this->head;
        if(this->size==1){
            this->head=NULL;
            this->tail=NULL;
        }
        else{
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
    Node * removeLastNode(){
        Node * node = this->tail;
        if(this->size==1){
            this->head=NULL;
            this->tail=NULL;
        }
        else{
            Node * prev = getAtNode(this->size-2);
            this->tail=prev;
            prev->next=NULL;
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
    Node * removeAtNode(int index){
        if(index==0){
            return removeFirstNode();
        }else if(index==this->size-1){
            return removeLastNode();
        }else{
            Node * prev = getAtNode(index-1);
            Node * curr = prev->next;
            prev->next=curr->next;
            curr->next=NULL;
            this->size--;
            return curr;
        }
    }
    int removeAt(int index){
        if(index<0 or index>=this->size){
            return -1;
        }
        Node * node = removeAtNode(index);
        int value = node->data;
        delete node;
        return value;
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
    ll.removeAt(2);
    ll.display();
    return 0;
}