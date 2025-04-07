//����һ ������洢
#define MAX(A,B) ((A) > (B)) ? A : B

int lengthOfLongestSubstring(char* s) {
    //�������ڸ�ʽ
    int left = 0, ans = 0;
    int cnt[128] = {};

    //cnt����ǳ��ִ�����s��Ķ�Ӧ�ַ�
    for (int right = 0; s[right]; right++)
    {
        char c = s[right];
        cnt[c]++;

        while (cnt[c] > 1)
        {
            cnt[s[left]]--;//��ǰ����ַ���Ӧ������һ����ΪҪ����
            left++;//���ƣ���������
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}