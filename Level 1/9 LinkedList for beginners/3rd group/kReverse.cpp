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
    
    Node * getFirstNode(){
        return this->head;
    }
    int getFirst(){
        if(this->size==0){
            return -1;
        }
        Node * node = getFirstNode();
        return node->data;
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
    void addLastNode(Node * node){
        if(this->size==0){
            this->head=node;
            this->tail=node;
        }
        else{
            this->tail->next=node;
            this->tail=node;
        }
        this->size++;
    }
    void addLast(int val){
        Node * node = new Node(val);
        addLastNode(node);
    }
    void kReverse(int k){
        LinkedList prev;
        while(this->size>0){
            LinkedList curr;
            if(this->size>=k){
                for(int i=0;i<k;i++){
                    int value = this->getFirst();
                    this->removeFirst();
                    curr.addFirst(value);
                }
            }else{
                int os = this->size;
                for(int i=0;i<os;i++){
                    int value = this->getFirst();
                    this->removeFirst();
                    curr.addLast(value);
                }
            }
            if(prev.size==0){
                prev=curr;
            }else{
                prev.tail->next=curr.head;
                prev.tail=curr.tail;
                prev.size+=curr.size;
            }
        }
        this->head=prev.head;
        this->tail=prev.tail;
        this->size+=prev.size;
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
    ll.addFirst(7);
    ll.display();
    ll.kReverse(3);
    ll.display();
    return 0;
}