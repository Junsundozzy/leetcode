/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* new_head = NULL;
    struct ListNode* next = NULL;
    while(head)
    {
        next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}