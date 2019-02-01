/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        
        while (fast) {
            fast = fast->next;
            slow = slow->next;
            if (!fast) {
                return NULL;
            }
            
            fast = fast->next;
            if (fast == slow) {
                meet = fast;
                break;
            }
        }
        
        if (meet == NULL) {
            return NULL;
        }
        while (head && meet) {
            if (head == meet) {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
       
    }
};