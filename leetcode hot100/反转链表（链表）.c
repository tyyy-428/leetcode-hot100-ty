/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //思路：将头节点的next改为NULL，在用双指针遍历
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;

    while (curr)
    {
        struct ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}