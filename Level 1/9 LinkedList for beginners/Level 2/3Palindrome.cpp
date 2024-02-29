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
ListNode *reverse(ListNode *head){
    ListNode * prev = nullptr,*curr = head,*next = nullptr;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode *midNode(ListNode *head){
    if(head==nullptr or head->next==nullptr) return head;
    ListNode * slow = head;
    ListNode * fast = head;
    while(fast->next!=nullptr and fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(ListNode *head)
{
    if(head==nullptr or head->next==nullptr) return true;
    ListNode * temp = head;
    ListNode * mid = midNode(head);
    ListNode * rev = reverse(mid);
    while(rev!=nullptr and temp!=nullptr){
        if(rev->val!=temp->val){
            return false;
        }
        rev = rev->next;
        temp = temp->next;
    }
    return true;
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}