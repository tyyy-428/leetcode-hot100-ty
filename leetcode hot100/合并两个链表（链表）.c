/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //�����ڱ��ڵ㵱����������׽ڵ㣨���⣩
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    //����˫ָ��
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;

    //��ʼƴ���µ�����
    while (p1 && p2)
    {
        if (p1->val <= p2->val)
        {
            //����ֱ�Ӹ�ֵ����Ϊcurr�����������׽ڵ㣬��p1��ַ��ֵ�Ӷ��ҵ��������׽ڵ�
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

    //����ʣ��ڵ㣨���������Ȳ���ʱ��
    curr->next = (p1 == NULL) ? p2 : p1;

    //�����������׽ڵ�
    return dummy.next;

}