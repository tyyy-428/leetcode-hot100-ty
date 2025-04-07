#define MIN(a,b) ((b) > (a)) ? (a) : (b)

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0;

    //ȷ��ans��ʼֵ����numsSize��������ȷ���´�
    int ans = numsSize + 1;

    //�������ڣ���rightΪ�ұ߽�
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        
        //���´�
        while (sum >= target)
        {
            //�������껹����target�����������
            ans = MIN(ans, right - left + 1);
            sum -= nums[left++];
        }
    }
    return ans <= numsSize ? ans : 0;
}
