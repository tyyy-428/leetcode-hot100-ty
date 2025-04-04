/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //设置哨兵节点当作新链表的首节点（虚拟）
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    //设置双指针
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;

    //开始拼接新的链表
    while (p1 && p2)
    {
        if (p1->val <= p2->val)
        {
            //不能直接赋值，因为curr现在是虚拟首节点，将p1地址赋值从而找到真正的首节点
            curr->next = p1;
            p1 = p1->next;
        }
        else
        {
            curr->next = p2;
            p2 = p2->next;
        }
        curr = curr->next;
    }

    //处理剩余节点（两个链表长度不等时）
    curr->next = (p1 == NULL) ? p2 : p1;

    //返回真正的首节点
    return dummy.next;

}