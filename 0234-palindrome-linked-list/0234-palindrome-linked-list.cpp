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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head; ListNode* prev = NULL; ListNode* nextNode = NULL;
        while(curr != NULL) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // find middle
        ListNode* slow = head; ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // reverse the halves
        ListNode* newHead = reverse(slow -> next);
        // compare them
        ListNode* first = head; ListNode* second = newHead;
        while(second != NULL) {
            if (first -> val != second -> val) {
                reverse(newHead); return false;
            }
            first = first -> next; second = second -> next;
        }
        reverse(newHead); return true;
    }
};