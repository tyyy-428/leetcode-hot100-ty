/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //快慢指针
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    //快指针永远是慢指针的两倍
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;

}