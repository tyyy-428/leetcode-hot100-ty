/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //����ָ��
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //����ָ��������˵���л�
        if (fast == slow)
        {

            //��ʱslow��head�뻷����������ͬ
            while (slow != head)
            {

                //ָ�����һ��ֻ����next
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }

    //˵��û�л�
    return NULL;
}