/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    //��ʼ��˫ָ��
    int left = 0;
    int right = numbersSize - 1;
    *returnSize = 2;

    //ע�������Ѱ��ǵݼ�˳������
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            int* arr = (int*)malloc(sizeof(int) * 2);
            arr[0] = left + 1;
            arr[1] = right + 1;
            return arr;
        }
        if (sum < target) left++;
        if (sum > target) right--;
    }
    return NULL;
}