/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //�ڱ��ڵ㣺����ɾ��ͷ�ڵ��������������Լ򻯴���
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    //���ÿ�ָ����n�����γ�����ָ���м�n�ľ��룬����ָ���ߵ�����ͷ��ʱ����ָ���Ӧ�����ڣ�n-1�����ڵ�
    while (n--) fast = fast->next;

    //������Բ�����n
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //����ɾ���Ľڵ㣬���ͷ��ڴ���ܻ�����ڴ�й¶
    struct ListNode* nxt = slow->next;
    slow->next = slow->next->next;
    free(nxt);
    return dummy.next;
}