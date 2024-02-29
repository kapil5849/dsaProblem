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
    void display(){
        for(Node * node=head;node!=NULL;node=node->next){
            cout<<node->data<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
    Node * getMidNode(Node * head,Node * tail){
        Node * slow = head,*fast=head;
        while(fast!=tail and fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    int getMid(){
        Node * node = getMidNode(this->head,this->tail);
        return node->data;
    }

    int midNode(){
        if(head==NULL){
            return -1;
        }
        Node * slow = head;
        Node * fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        int value = slow->data;
        return value;
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
    cout<<ll.getMid()<<endl;
    cout<<ll.midNode()<<endl;
    return 0;
}