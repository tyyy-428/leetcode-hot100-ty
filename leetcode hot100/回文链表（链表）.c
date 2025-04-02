/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//����һ�����������������飬�ж��Ƿ�Ϊ����

bool isPalindrome(struct ListNode* head) {
    struct ListNode* p = head;
    int N = 1;

    //����������
    while (p->next != NULL)
    {
        N++;
        p = p->next;
    }

    //���䶯̬�ڴ�
    int* arr = (int*)malloc(sizeof(int) * N);
    if (arr == NULL) return false;
    
    //������Ԫ�ش�������
    p = head;
    for (int i = 0; i < N; i++)
    {
        arr[i] = p->val;
        p = p->next;
    }

    //�ж��Ƿ�Ϊ����
    int* left = &arr[0];
    int* right = &arr[N - 1];
    while (left < right)
    {
        if (*left == *right)
        {
            left++;
            right--;
        }
        else if (*left != *right) return false;
    }
    return true;
}

//������������ָ��+��ת����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�м�ڵ�
struct ListNode* midNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//��ת����
struct ListNode* turn_List(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;
    while (curr)
    {
        struct ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* mid = midNode(head);
    struct ListNode* head2 = turn_List(mid);
    while (head2)
    {
        //head2�Ƿ�ת��Ķ���������head�жϣ����һ�ε��´���
        if (head->val != head2->val) return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;

}