//方法一 ：暴力解法
//合并后排序：不用内置函数法
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* nums = (int*)malloc(sizeof(int) * (m + n));
    //合并数组
    for (int i = 0; i < m; i++)
    {
        nums[i] = nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[m + i] = nums2[i];
    }

    //新数组排序
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

    //重新赋值nums1
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = nums[i];
    }
}

//方法二：双指针  （指针指的是下标）
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int sorted[m + n];
    int p1 = 0, p2 = 0;

    //只遍历一遍，同样先使用第三个数组来储存排序后的数字
    for (int i = 0; i < m + n; i++)
    {
        //前两个if语句用来判断nums1或者nums2是否已经遍历结束，结束就接另个数字剩余数字
        //不是（m-1）或者（n-1）的原因是 有p1++和p2++的存在
        if (p1 == m)
        {
            sorted[i] = nums2[p2++];
        }
        else
            if (p2 == n)
            {
                sorted[i] = nums1[p1++];
            }

        //当下标未遍历完，则正常进行比较
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