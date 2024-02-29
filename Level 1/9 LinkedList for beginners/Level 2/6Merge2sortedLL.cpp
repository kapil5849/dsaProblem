#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};
ListNode *mergeTwoListsRecursive(ListNode * l1, ListNode * l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->val<l2->val){
        l1->next = mergeTwoListsRecursive(l1->next,l2);
        return l1;
    }
    else{
        l2->next = mergeTwoListsRecursive(l1,l2->next);
        return l2;
    }
}
// iterative solution... 
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode * p1 = l1;
    ListNode * p2 = l2;
    ListNode * dummy = new ListNode(-1);
    ListNode * ans = dummy;
    while(p1!=NULL and p2!=NULL){
        if(p1->val<p2->val){
            dummy->next = p1;
            p1 = p1->next;
            dummy = dummy->next;
        }else{
            dummy->next = p2;
            p2 = p2->next;
            dummy = dummy->next;
        }
    }
    if(p1!=NULL){
        dummy->next = p1;
    }
    if(p2!=NULL){
        dummy->next = p2;
    }
    return ans->next;
}
void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    // ListNode *head = mergeTwoLists(h1, h2);
    // printList(head);

    ListNode *head = mergeTwoListsRecursive(h1, h2);
    printList(head);

    return 0;
}