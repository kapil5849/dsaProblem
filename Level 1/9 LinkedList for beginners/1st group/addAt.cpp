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
    void addAtNode(Node * node,int index){
        if(index==0){
            addFirstNode(node);
        }else if(index==this->size){
            addLastNode(node);
        }else{
            Node * prev = getAtNode(index-1);
            Node * curr = prev->next;
            prev->next=node;
            node->next=curr;
            this->size++;
        }
    }
    void addAt(int value,int index){
        if(index<0 or index>=this->size){
            cout<<"Invalid"<<endl;
        }
        Node * node = new Node(value);
        addAtNode(node,index);
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
    ll.addAt(8,2);
    ll.display();
    return 0;
}