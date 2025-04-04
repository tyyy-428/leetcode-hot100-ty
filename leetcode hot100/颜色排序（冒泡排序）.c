//����һ��ð������
//ʱ�临�Ӷ�O(n^2)    ʹ��ÿһ�ֽ�������һ��������С���������
void sortColors(int* nums, int numsSize) {
    //�ؼ�����������ѭ������
    //��ѭ�������������������
    for (int i = 0; i < numsSize - 1; i++)
    {
        //��ѭ����ʾ����ıȽ�Ԫ��
        for (int j = 0; j < numsSize - 1 - i; j++)
        {
            if (nums[j + 1] < nums[j])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

//����������ָ������ ʱ�临�Ӷ�O(n��
//����ֵҪ�õ�ַ
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int ptr = 0;

    //��ptr����0��ʼ������±꣬����0��������Ӧλ�ã�λ�ú���
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            swap(&nums[i], &nums[ptr]);
            ptr++;
        }
    }

    //��ptr����1��ʼ������±꣬��Ϊ��ptr�������ڣ�����ptr������0����ʱ���±�
    for (int i = ptr; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            swap(&nums[i], &nums[ptr]);
            ptr++;
        }
    }
}