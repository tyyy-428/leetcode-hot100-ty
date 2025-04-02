/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：遍历链表，存入数组，判断是否为回文

bool isPalindrome(struct ListNode* head) {
    struct ListNode* p = head;
    int N = 1;

    //计算链表长度
    while (p->next != NULL)
    {
        N++;
        p = p->next;
    }

    //分配动态内存
    int* arr = (int*)malloc(sizeof(int) * N);
    if (arr == NULL) return false;
    
    //将链表元素存入数组
    p = head;
    for (int i = 0; i < N; i++)
    {
        arr[i] = p->val;
        p = p->next;
    }

    //判断是否为回文
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

//方法二：快慢指针+反转链表法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//中间节点
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
//反转链表
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
        //head2是反转后的短链表；若用head判断，会多一次导致错误
        if (head->val != head2->val) return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;

}