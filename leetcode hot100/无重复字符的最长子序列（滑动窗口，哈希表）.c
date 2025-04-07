//方法一 用数组存储
#define MAX(A,B) ((A) > (B)) ? A : B

int lengthOfLongestSubstring(char* s) {
    //滑动窗口格式
    int left = 0, ans = 0;
    int cnt[128] = {};

    //cnt存的是出现次数，s存的对应字符
    for (int right = 0; s[right]; right++)
    {
        char c = s[right];
        cnt[c]++;

        while (cnt[c] > 1)
        {
            cnt[s[left]]--;//当前左端字符对应次数减一，因为要左移
            left++;//左移，窗口缩短
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}