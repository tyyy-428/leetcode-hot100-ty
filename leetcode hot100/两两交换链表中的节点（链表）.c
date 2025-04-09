/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    //哨兵节点
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    //确保至少有两个节点可以进行互换
    while (prev->next && prev->next->next)
    {
        //节点在循环内互换
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;
        struct ListNode* newpair = second->next;

        //没有prev这一行，两两节点就断开了
        prev->next = second;
        second->next = first;
        first->next = newpair;

        //更新，因为下一轮循环会再将first后移一个节点
        prev = first;
    }
    return dummy.next;

}