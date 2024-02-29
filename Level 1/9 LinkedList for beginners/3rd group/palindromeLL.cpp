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
    bool isPalindromeHelper(Node * right){
        if(right==NULL){
            return true;
        }
        bool ans = isPalindromeHelper(right->next);
        if(ans==false){
            return false;
        }else if(left->data!=right->data){
            return false;
        }else{
            left=left->next;
            return true;
        }
    }
    Node * left;
    bool isPalindrome(){
        left=head;
        return isPalindromeHelper(head);
    }
};
int main(){
    LinkedList ll;
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(2);
    ll.addFirst(1);
    ll.display();
    cout<<ll.isPalindrome()<<endl;
    return 0;
}