
typedef struct {
    char key[101];
    char** group;//�洢ͬһ����λ����ԭ�����е��±�
    int groupSize;//��ϣ���ڶ�Ӧ����λ�ʳ��ֵĴ���
    UT_hash_handle hh;
} hash;

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    //��ʼ����ϣ��
    hash* groups = NULL;

    //���ַ��������еĴ�������ϣ����
    for (int i = 0; i < strsSize; ++i) {
        char* original = strs[i];
        //����һ���µ����飬�Է��ƻ�ԭ����
        char* sorted = (char*)malloc(strlen(original) + 1);
        strcpy(sorted, original);
        qsort(sorted, strlen(original), sizeof(char), cmp);

        //entry�������ֵ
        hash* entry = NULL;
        HASH_FIND_STR(groups, sorted, entry);
        if (entry == NULL)
        {
            entry = (hash*)malloc(sizeof(hash));
            strcpy(entry->key, sorted);
            //malloc����ֵ��һ��ָ�룬Ϊһ��char*����ռ䣬���Է���ֵ�Ƕ���ָ��
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

    //��ϣ���еļ�ֵ�ԣ�Ҳ��������
    *returnSize = HASH_COUNT(groups);
    //�����ڴ洢��ÿһ�еĸ���������whyreturnSize*
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    //�����ڴ洢��ÿ����ַ������飿����
    char*** result = (char***)malloc(*returnSize * sizeof(char**));

    //Ҳ�е�С����
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