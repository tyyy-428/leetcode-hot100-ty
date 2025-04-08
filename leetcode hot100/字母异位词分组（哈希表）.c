
typedef struct {
    char key[101];
    char** group;//存储同一组异位词在原数组中的下标
    int groupSize;//哈希表内对应的异位词出现的次数
    UT_hash_handle hh;
} hash;

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    //初始化哈希表
    hash* groups = NULL;

    //将字符串数组中的词语放入哈希表中
    for (int i = 0; i < strsSize; ++i) {
        char* original = strs[i];
        //复制一个新的数组，以防破坏原数组
        char* sorted = (char*)malloc(strlen(original) + 1);
        strcpy(sorted, original);
        qsort(sorted, strlen(original), sizeof(char), cmp);

        //entry输出返回值
        hash* entry = NULL;
        HASH_FIND_STR(groups, sorted, entry);
        if (entry == NULL)
        {
            entry = (hash*)malloc(sizeof(hash));
            strcpy(entry->key, sorted);
            //malloc返回值是一个指针，为一个char*分配空间，所以返回值是二级指针
            entry->group = (char**)malloc(sizeof(char*));

            entry->group[0] = original;
            entry->groupSize = 1;
            HASH_ADD_STR(groups, key, entry);
        }
        else {
            entry->group = (char**)realloc(entry->group, (entry->groupSize + 1) * sizeof(char*));
            entry->group[entry->groupSize] = original;
            entry->groupSize++;
        }
        free(sorted);
    }

    //哈希表中的键值对，也就是行数
    *returnSize = HASH_COUNT(groups);
    //分配内存储存每一行的个数？？？whyreturnSize*
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    //分配内存储存每组的字符串数组？？？
    char*** result = (char***)malloc(*returnSize * sizeof(char**));

    //也有点小问题
    int index = 0;
    hash* current, * tmp;
    HASH_ITER(hh, groups, current, tmp) {
        (*returnColumnSizes)[index] = current->groupSize;
        result[index] = current->group;
        index++;
        HASH_DEL(groups, current);
        free(current);
    }

    return result;
}