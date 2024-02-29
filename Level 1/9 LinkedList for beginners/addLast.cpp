#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data=0;
    Node* next=NULL;
    Node(int data){
        this->data=data;
    }
};

class linkedlist{
    public:
    Node *head=NULL;
    Node *tail=NULL;
    int size=0;

    // size function...
    int size_(){
        return this->size;
    }

    // check list is empty or not...
    bool isEmpty(){
        return this->size==0;
    }

    // add fist in linked list...
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

    // add last in linked list... 
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

    // add at in linked list...
    void addAtNode(Node * node,int index){
        if(index==0){
            addFirstNode(node);
        }
        else if(index==this->size){
            addLastNode(node);
        }
        else{
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

    // display a linked list...
    void display(){
        for(Node * node=head;node!=NULL;node=node->next){
            cout<<node->data<<" -> ";
        } 
        cout<<"NULL"<<endl;
    }

    // remove first in linked list...
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

    // remove last in linked list...
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

    // remove at in linked list...
    Node * removeAtNode(int index){
        if(index==0){
            return removeFirstNode();
        }
        else if(index == this->size-1){
            return removeLastNode();
        }
        else{
            Node * prev=getAtNode(index-1);
            Node * curr=prev->next;
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
        int value=node->data;
        delete node;
        return value;
    }

    // get...
    // get first in linked list...
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

    Node * getLastNode(){
        return this->tail;
    }
    int getLast(){
        if(this->size==0){
            return -1;
        }
        Node * node = getLastNode();
        return node->data;
    }

    Node * getAtNode(int index){
        Node * curr = this->head;
        while(index-- > 0){
            curr=curr->next;
        }
        return curr;
    }
    int getAt(int index){
        if(index<0 or index>=this->size){
            return -1;
        }
        Node * node = getAtNode(index);
        return node->data;
    }
    
    Node* getMidNode(Node* head, Node* tail){
        Node* slow = head, *fast = head;
        while(fast!=tail and fast->next!=tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    int getMid(){
        Node * node = getMidNode(this->head,this->tail);
        return node->data;
    }

    // reverse linked list through iterative method... 
    void reverse_di(){
        int l=0;
        int r=this->size-1;
        while(l<r){
            Node * left = getAtNode(l);
            Node * right =  getAtNode(r);
            int temp = left->data;
            left->data = right->data;
            right->data = temp;
            l++;
            r--;
        }
    }

    // reverse linked list through pointer method...
    void reverse_pi(){
        Node * prev = NULL;
        Node * curr = head;
        while(curr!=NULL){
            Node * next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        Node * temp = head;
        head = tail;
        tail = temp;
    } 
    // 1->2->3->4->5->6->NULL

    void displayReverseRecursiveHelper(Node * node){
        if(node==NULL){
            return;
        }
        displayReverseRecursiveHelper(node->next);
        cout<<node->data<<" -> ";
    }
    void displayReverseRecursive(){
        displayReverseRecursiveHelper(head);
        cout<<"NULL"<<endl;
    }
    
    void displayReversePointerRecHelper(Node * node){
        if(node==NULL){
            return;
        }
        displayReversePointerRecHelper(node->next);
        if(node==tail){

        }else{
            node->next->next=node;
        }
    }

    void displayReversePointerRec(){
        displayReversePointerRecHelper(head);
        head->next=NULL;
        Node * temp=head;
        head=tail;
        tail=temp;
    }


    // find kth from the end...
    int Kth_from_end(int k){
        if(head==NULL or k>=this->size){
            cout<<"List is empty";
            return -1;
        }
        Node * slow = head;
        Node * fast = head;
        for(int i=0;i<k;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
    }

    // find the mid of linked list...
    int mid(){
        if(head==NULL){
            return -1;
        }
        Node * slow = head;
        Node * fast = head;
        while (fast->next!=NULL and fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        int value= slow->data;
        return value;
    }

    // merge two sorted linked list...
    void mergeTwoSortedLinkedList(linkedlist la,linkedlist lb){
        Node * one = la.head;
        Node * two = lb.head;
        while(one!=NULL and two!=NULL){
            if(one->data<two->data){
                this->addLast(one->data);
                one=one->next;
            }
            else{
                this->addLast(two->data);
                two=two->next;
            }
        }
        while(one!=NULL){
            this->addLast(one->data);
            one=one->next;
        }
        while(two!=NULL){
            this->addLast(two->data);
            two=two->next;
        }
    }


    void removeDuplicate(){
        linkedlist ans;
        while(this->size>0){
            int value=this->getFirst();
            this->removeFirst();
            if(ans.size==0 or ans.tail->data!=value){
                ans.addLast(value);
            }
        }
        this->head=ans.head;
        this->tail=ans.tail;
        this->size=ans.size;
    }

    void oddEven(){
        linkedlist odd;
        linkedlist even;
        while(this->size>0){
            int value = this->getFirst();
            this->removeFirst();
            if(value%2==0){
                even.addLast(value);
            }
            else{
                odd.addLast(value);
            }
        }
        if(odd.size>0 and even.size>0){
            odd.tail->next=even.head;
            this->head=odd.head;
            this->tail=even.tail;
            this->size=odd.size+even.size;
        }
        else if(odd.size>0){
            this->head=odd.head;
            this->tail=odd.tail;
            this->size=odd.size;
        }
        else if(even.size>0){
            this->head=even.head;
            this->tail=even.tail;
            this->size=even.size;
        }
    }

    void kReverse(int k){
        linkedlist prev;
        while(this->size>0){
            linkedlist curr;
            if(this->size>=k){
                for(int i=0;i<k;i++){
                    int value = this->getFirst();
                    this->removeFirst();
                    curr.addFirst(value);
                }
            }
            else{
                int os = this->size;
                for(int i=0;i<os;i++){
                    int value = this->getFirst();
                    this->removeFirst();
                    curr.addLast(value);
                }
            }
            if(prev.size==0){
                prev=curr;
            }
            else{
                prev.tail->next=curr.head;
                prev.tail=curr.tail;
                prev.size+=curr.size;
            }
        }
        this->head=prev.head;
        this->tail=prev.tail;
        this->size+=prev.size;
    }

    bool is_palindrome_Helper(Node * p_right){
        if(p_right==NULL){
            return true;
        }
        bool r_ans = is_palindrome_Helper(p_right->next);
        if(r_ans==false){
            return false;
        }
        else if(p_left->data!=p_right->data){
            return false;
        }
        else{
            p_left=p_left->next;
            return true;
        }
    }
    Node * p_left;
    bool is_palindrome(){
        p_left=head;
        return is_palindrome_Helper(head);
    }

    void foldHelper(Node * pr,int floor){
        if(pr==NULL){
            return;
        }
        foldHelper(pr->next,floor+1);
        if(floor> this->size /2){
            Node * temp = pl->next;
            pl->next=pr;
            pr->next=temp;
            pl=temp;
        }
        else if(floor==this->size /2){
            tail=pr;
            tail->next=NULL;
        }
    }
    Node * pl;
    void fold(){
        pl=head;
        foldHelper(head,0);
    }

};

class LLtoStack{
    public:
    linkedlist l;
    int size_s(){
        return l.size_();
    }
    void push(int value){
        l.addFirst(value);
    }
    int pop(){
        if(l.size_()==0){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int value = l.getFirst();
        l.removeFirst();
        return value;
    }
    int top(){
        if(l.size_()==0){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return l.getFirst();
    }
};

class LLtoQueue{
    public:
    linkedlist l;
    int size_q(){
        return l.size_();
    }
    void add(int value){
        l.addLast(value);
    }
    int remove(){
        if(l.size_()==0){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int value = l.getFirst();
        l.removeFirst();
        return value;
    }
    int top_q(){
        if(l.size_()==0){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return l.getFirst();
    }
};

Node* getMid_out(Node* head, Node* tail){
    Node* slow = head, *fast = head;
    while(fast->next != tail && fast->next->next != tail){
        fast = fast->next->next;
        slow = slow->next;
    }    
    return slow;
}

linkedlist mergeTwoSortedLists_out(linkedlist l1, linkedlist l2) {
    linkedlist ans;
    Node* one = l1.head;
    Node* two = l2.head;
    while(one != nullptr && two != nullptr){
        if(one->data < two->data){
            ans.addLast(one->data);
            one = one->next;
        }else{
            ans.addLast(two->data);
            two = two->next;
        }
    }
    while(one!=nullptr){
        ans.addLast(one->data);
        one = one->next;
     }
     while(two !=nullptr){
        ans.addLast(two->data);
        two = two->next;
    }
    return ans;
}

linkedlist mergeSort_out(Node* head,Node* tail ){
    if(head == tail){
        linkedlist base;
        base.addLast(head->data);
        return base;
    }
    Node* mid = getMid_out(head,tail);
    linkedlist fsh = mergeSort_out(head, mid);
    linkedlist ssh = mergeSort_out(mid->next, tail);    
    return mergeTwoSortedLists_out(fsh,ssh);
}

int main(){
    linkedlist l,al,bl;
    Node * head=NULL;
    l.addFirst(1);
    l.addFirst(2);
    l.addFirst(3);
    l.addFirst(4);
    l.addLast(5);
    l.addLast(6);
    l.addLast(4);
    l.display();
    l.removeFirst();
    l.display();
    int x=l.getFirst();
    int y=l.getLast();
    int z=l.getAt(2);
    cout<<x<<" "<<y<<" "<<z<<endl;
    l.display();
    l.addAt(7,3);
    l.display();
    l.removeLast();
    l.display();
    l.addLast(6);
    l.display();
    l.removeAt(2);
    l.display();
    l.addAt(1,2);
    l.display();
    Node * temp = l.removeAtNode(2);
    l.display();
    cout<<temp->data<<endl;
    l.display();
    cout<<l.size_()<<endl;
    l.reverse_di();
    l.display();
    l.reverse_pi();
    l.display();

    LLtoStack ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
    ll.push(50);
    ll.push(60);
    cout<<ll.size_s()<<" ";
    cout<<ll.top()<<" ";
    cout<<ll.pop()<<" ";
    cout<<ll.size_s()<<" ";
    cout<<endl;

    LLtoQueue lll;
    lll.add(10);
    lll.add(20);
    lll.add(30);
    lll.add(40);
    lll.add(50);
    lll.add(60);
    cout<<lll.size_q()<<" ";
    cout<<lll.top_q()<<" ";
    cout<<lll.remove()<<" ";
    cout<<lll.size_q()<<" ";
    cout<<endl;
    cout<<l.Kth_from_end(5)<<endl;
    cout<<l.mid()<<endl;

    al.addLast(10);
    al.addLast(20);
    al.addLast(30);
    al.addLast(70);

    bl.addLast(1);
    bl.addLast(2);
    bl.addLast(3);
    bl.addLast(7);

    al.display();
    bl.display();

    linkedlist m;
    m.mergeTwoSortedLinkedList(al,bl);
    m.display();

    cout<<m.getMid()<<endl;
    l.display();
    linkedlist ans = mergeSort_out(l.head,l.tail);
    ans.display();

    l.removeDuplicate();
    l.display();

    l.oddEven();
    l.display();

    m.display();
    m.kReverse(4);
    m.display();


    m.displayReverseRecursive();
    m.display();

    cout<<"nikita"<<endl;

    m.displayReversePointerRec();
    m.display();

    // cout<<m.is_palindrome();
    if(m.is_palindrome()==0){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }

    m.fold();
    m.display();
    return 0;
}
