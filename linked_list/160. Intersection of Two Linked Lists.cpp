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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> nodeset;
        while(headA)
        {
            nodeset.insert(headA);
            headA = headA->next;
        }
        
        while(headB)
        {
            if(nodeset.find(headB) != nodeset.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};