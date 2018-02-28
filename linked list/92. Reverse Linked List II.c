/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* result = head;
    struct ListNode* pre_head = NULL;
    struct ListNode* new_head = NULL;
    struct ListNode* modify_tail = NULL;
    struct ListNode* next = NULL;
    int num_change = n - m + 1;
    
    while(head && --m)
    {
        pre_head = head;
        head = head->next;
    }
    
    modify_tail = head;
    
    while(head && num_change)
    {
        next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        num_change--;
    }
    
    modify_tail->next = head;
    if(pre_head)
    {
        pre_head->next = new_head;
    }
    else
    {
        result = new_head;
    }
    
    return result;
}