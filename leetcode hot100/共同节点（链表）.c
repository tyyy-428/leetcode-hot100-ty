/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //���ж�����ͷ�Ƿ�Ϊ�գ�����ǿ���ֱ�ӷ���NULL
    if (headA == NULL || headB == NULL)
        return NULL;

    //����A,B�����ָ�룬�����ƶ��Ա��Ƿ�Ϊ��ͬ�ڵ�
    struct ListNode* pa = headA;
    struct ListNode* pb = headB;

    //�жϣ�����ƶ�a+b�Σ�a��b�����ȿ��ܲ�ͬ��a+b�κ�һ�����ҵ���ͬ�ڵ㣨�����ڣ�
    //������pa = NULL
    while (pa != pb)
    {
        pa = pa == NULL ? headB : pa->next;
        pb = pb == NULL ? headA : pb->next;
    }
    return pa;
}