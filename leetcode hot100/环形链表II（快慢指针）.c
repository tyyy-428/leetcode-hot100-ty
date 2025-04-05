/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //快慢指针
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //快慢指针相遇，说明有环
        if (fast == slow)
        {

            //此时slow和head与环的起点距离相同
            while (slow != head)
            {

                //指针的下一步只能用next
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }

    //说明没有环
    return NULL;
}