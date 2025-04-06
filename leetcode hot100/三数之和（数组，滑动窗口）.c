/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//排序函数需要的比较函数
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    
    //与两数之和II类似，先排序
    qsort(nums, n, sizeof(int), cmp);
    int** ans = malloc(sizeof(int*) * n * n);
    *returnColumnSizes = malloc(sizeof(int) * n * n);
    
    //m表示结果二维数组的行数
    int m = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int x = nums[i];
        
        //去除重复元素
        if (i > 0 && x == nums[i - 1]) continue;

        //优化剪枝
        if (x + nums[n - 1] + nums[n - 2] < 0) continue;
        if (x + nums[i + 1] + nums[i + 2] > 0) break;

        //双指针（滑动窗口）
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (x + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else if (x + nums[j] + nums[k] < 0)
            {
                j++;
            }
            //==0，找到一个三元组
            else {
                int* tuple = malloc(sizeof(int) * 3);
                tuple[0] = nums[i];
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[m] = tuple;
                
                //告诉测评机每个三元组的大小
                (*returnColumnSizes)[m++] = 3;

                //去除重复元素
                //先移动到下一个元素，如果和上一个相同，继续移动
                for (j++; j < k && nums[j] == nums[j - 1]; j++);
                for (k--; k > j && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    //说明有几组三元组
    *returnSize = m;
    return ans;
}