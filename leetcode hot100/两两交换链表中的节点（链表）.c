/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    //�ڱ��ڵ�
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    //ȷ�������������ڵ���Խ��л���
    while (prev->next && prev->next->next)
    {
        //�ڵ���ѭ���ڻ���
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;
        struct ListNode* newpair = second->next;

        //û��prev��һ�У������ڵ�ͶϿ���
        prev->next = second;
        second->next = first;
        first->next = newpair;

        //���£���Ϊ��һ��ѭ�����ٽ�first����һ���ڵ�
        prev = first;
    }
    return dummy.next;

}