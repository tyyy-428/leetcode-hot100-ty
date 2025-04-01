/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //先判断链表头是否为空，如果是空则直接返回NULL
    if (headA == NULL || headB == NULL)
        return NULL;

    //设置A,B链表的指针，用于移动对比是否为共同节点
    struct ListNode* pa = headA;
    struct ListNode* pb = headB;

    //判断，最多移动a+b次：a，b链表长度可能不同，a+b次后一定能找到共同节点（若存在）
    //不存在pa = NULL
    while (pa != pb)
    {
        pa = pa == NULL ? headB : pa->next;
        pb = pb == NULL ? headA : pb->next;
    }
    return pa;
}