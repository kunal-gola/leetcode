/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* cur){

        ListNode* slow = cur, *fast = cur->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* cur){

        // if (cur == NULL || cur-> next == NULL){
        //     return cur;
        // }

        // ListNode* newHead = reverse(cur->next);

        // ListNode* headNext = cur->next;
        // headNext->next = cur;
        // cur->next = NULL;
        // return newHead;

        ListNode *curr = cur, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
    }
    int pairSum(ListNode* head) {

        int curSum = 0, maxSum = 0;
        ListNode *mid = findMid(head);

        cout<<mid->val<<"\n";

        ListNode *tail = reverse(mid);


        while(head != NULL){
            cout<< head->val<<" - "<<tail->val<<"\n";
            curSum = head->val + tail->val;
            maxSum = max(curSum, maxSum);
            head = head->next;
            tail = tail->next;
        }

        return maxSum;
        
    }
};