#define MIN(a,b) ((b) > (a)) ? (a) : (b)

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0;

    //确保ans初始值大于numsSize，便于正确更新答案
    int ans = numsSize + 1;

    //滑动窗口，以right为右边界
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        
        //更新答案
        while (sum >= target)
        {
            //若更新完还大于target，会继续左移
            ans = MIN(ans, right - left + 1);
            sum -= nums[left++];
        }
    }
    return ans <= numsSize ? ans : 0;
}
