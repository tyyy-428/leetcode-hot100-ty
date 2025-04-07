int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    //��ȷ���г�������� ������������0
    if (k <= 1) return 0;

    //�������ڸ�ʽ�����Ҷ˵�Ϊ�߽磬������˵㣩
    int left = 0, mul = 1, ans = 0;

    for (int right = 0; right < numsSize; right++)
    {

        mul *= nums[right];

        while (mul >= k)
        {
            mul /= nums[left++];
        }

        //���´𰸣��������������������������Ƶ�)
        ans += right - left + 1;
    }
    return ans;
}