//方法一：冒泡排序
//时间复杂度O(n^2)    使得每一轮结束出现一个最大或最小的数在最边
void sortColors(int* nums, int numsSize) {
    //关键：设置内外循环条件
    //外循环：控制排序的轮数。
    for (int i = 0; i < numsSize - 1; i++)
    {
        //内循环表示具体的比较元素
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

//方法二：单指针排序 时间复杂度O(n）
//交换值要用地址
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int ptr = 0;

    //用ptr当作0开始排序的下标，出现0，排序到相应位置，位置后移
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            swap(&nums[i], &nums[ptr]);
            ptr++;
        }
    }

    //用ptr当作1开始排序的下标，因为在ptr作用域内，所以ptr保存着0结束时的下标
    for (int i = ptr; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            swap(&nums[i], &nums[ptr]);
            ptr++;
        }
    }
}