//此时我们不关心元素出现的个数，而是出现与否
//UT_hash_handle hh 必须要有；key代表下标，val代表值
typedef struct {
    int key;
    UT_hash_handle hh;
}hash;

int longestConsecutive(int* nums, int numsSize) {
    //建立一个空的哈希表，必须初始化为NULL
    hash* table = NULL;
    hash* e;


    for (int i = 0; i < numsSize; i++)
    {
        //e是输出值
        HASH_FIND_INT(table, &nums[i], e);
        if (e == NULL)
        {
            e = (hash*)malloc(sizeof(hash));
            e->key = nums[i];
            //e是待插入的结构体
            HASH_ADD_INT(table, key, e);
        }
    }

    int ans = 0;
    //tmp不用赋值但必须先声明
    hash* tmp;
    //e：当前的键值对
    HASH_ITER(hh, table, e, tmp)
    {
        //遍历时，x作为起点，用x-1确保x是该连续序列的开头
        //比如1，2，3，4，5 | 2，3，4，5 这两个序列的最长连续应该是1开头，而不是2
        //遍历到2的时候我们可以直接跳过，因为已经计算过其所处的最长序列。这就是y的作用
        int x = e->key;
        int y = x - 1;
        HASH_FIND_INT(table, &y, e);
        if (e)
        {
            continue;
        }
        //x是起点，开始计数
        y = x;
        do {
            y++;
            HASH_FIND_INT(table, &y, e);

        } while (e);
        //更新
        ans = (ans > (y - x)) ? ans : (y - x);

    }
    //释放哈希表节点，避免内存泄漏
    HASH_ITER(hh, table, e, tmp)
    {
        HASH_DEL(table, e);
        free(e);
    }

    return ans;
}