int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    //正确运行程序的条件 测试用例中有0
    if (k <= 1) return 0;

    //滑动窗口格式（以右端点为边界，滑动左端点）
    int left = 0, mul = 1, ans = 0;

    for (int right = 0; right < numsSize; right++)
    {

        mul *= nums[right];

        while (mul >= k)
        {
            mul /= nums[left++];
        }

        //更新答案，满足条件的子数组数量（需推导)
        ans += right - left + 1;
    }
    return ans;
}