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

ListNode *reverse(ListNode* head){
    ListNode* curr=head,*prev=nullptr,*nex=nullptr;
    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}
void unfold(ListNode *head)
{
    if(head==NULL or head->next==NULL) return;
    ListNode * fh = head;
    ListNode * fp = fh;
    ListNode * sh = head->next;
    ListNode * sp = sh;
    while(sp!=NULL and sp->next!=NULL){
        ListNode * f = sp->next;
        fp->next = f;
        sp->next = f->next;
        fp = fp->next;
        sp = sp->next;
    }
    fp->next = NULL;
    sh = reverse(sh);
    fp->next = sh;
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

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    unfold(head);
    printList(head);

    return 0;
}