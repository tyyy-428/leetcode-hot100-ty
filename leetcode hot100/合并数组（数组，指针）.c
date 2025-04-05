//����һ �������ⷨ
//�ϲ������򣺲������ú�����
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* nums = (int*)malloc(sizeof(int) * (m + n));
    //�ϲ�����
    for (int i = 0; i < m; i++)
    {
        nums[i] = nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[m + i] = nums2[i];
    }

    //����������
    for (int i = 0; i < m + n - 1; i++)
    {
        for (int j = 0; j < m + n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    //���¸�ֵnums1
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = nums[i];
    }
}

//��������˫ָ��  ��ָ��ָ�����±꣩
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int sorted[m + n];
    int p1 = 0, p2 = 0;

    //ֻ����һ�飬ͬ����ʹ�õ�������������������������
    for (int i = 0; i < m + n; i++)
    {
        //ǰ����if��������ж�nums1����nums2�Ƿ��Ѿ����������������ͽ��������ʣ������
        //���ǣ�m-1�����ߣ�n-1����ԭ���� ��p1++��p2++�Ĵ���
        if (p1 == m)
        {
            sorted[i] = nums2[p2++];
        }
        else
            if (p2 == n)
            {
                sorted[i] = nums1[p1++];
            }

        //���±�δ�����꣬���������бȽ�
            else
                if (nums1[p1] <= nums2[p2])
                {
                    sorted[i] = nums1[p1++];
                }
                else
                    if (nums2[p2] < nums1[p1])
                    {
                        sorted[i] = nums2[p2++];
                    }
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = sorted[i];
    }

}