/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//��������Ҫ�ıȽϺ���
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    
    //������֮��II���ƣ�������
    qsort(nums, n, sizeof(int), cmp);
    int** ans = malloc(sizeof(int*) * n * n);
    *returnColumnSizes = malloc(sizeof(int) * n * n);
    
    //m��ʾ�����ά���������
    int m = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int x = nums[i];
        
        //ȥ���ظ�Ԫ��
        if (i > 0 && x == nums[i - 1]) continue;

        //�Ż���֦
        if (x + nums[n - 1] + nums[n - 2] < 0) continue;
        if (x + nums[i + 1] + nums[i + 2] > 0) break;

        //˫ָ�루�������ڣ�
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
            //==0���ҵ�һ����Ԫ��
            else {
                int* tuple = malloc(sizeof(int) * 3);
                tuple[0] = nums[i];
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[m] = tuple;
                
                //���߲�����ÿ����Ԫ��Ĵ�С
                (*returnColumnSizes)[m++] = 3;

                //ȥ���ظ�Ԫ��
                //���ƶ�����һ��Ԫ�أ��������һ����ͬ�������ƶ�
                for (j++; j < k && nums[j] == nums[j - 1]; j++);
                for (k--; k > j && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    //˵���м�����Ԫ��
    *returnSize = m;
    return ans;
}