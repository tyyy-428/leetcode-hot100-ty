/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //哨兵节点：用于删除头节点的特殊情况，可以简化代码
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    //先让快指针走n步，形成左右指针中间n的距离，当快指针走到链表尽头的时候，慢指针对应倒数第（n-1）个节点
    while (n--) fast = fast->next;

    //保持相对不动，n
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //处理删除的节点，不释放内存可能会造成内存泄露
    struct ListNode* nxt = slow->next;
    slow->next = slow->next->next;
    free(nxt);
    return dummy.next;
}