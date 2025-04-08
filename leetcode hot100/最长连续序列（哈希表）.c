//��ʱ���ǲ�����Ԫ�س��ֵĸ��������ǳ������
//UT_hash_handle hh ����Ҫ�У�key�����±꣬val����ֵ
typedef struct {
    int key;
    UT_hash_handle hh;
}hash;

int longestConsecutive(int* nums, int numsSize) {
    //����һ���յĹ�ϣ�������ʼ��ΪNULL
    hash* table = NULL;
    hash* e;


    for (int i = 0; i < numsSize; i++)
    {
        //e�����ֵ
        HASH_FIND_INT(table, &nums[i], e);
        if (e == NULL)
        {
            e = (hash*)malloc(sizeof(hash));
            e->key = nums[i];
            //e�Ǵ�����Ľṹ��
            HASH_ADD_INT(table, key, e);
        }
    }

    int ans = 0;
    //tmp���ø�ֵ������������
    hash* tmp;
    //e����ǰ�ļ�ֵ��
    HASH_ITER(hh, table, e, tmp)
    {
        //����ʱ��x��Ϊ��㣬��x-1ȷ��x�Ǹ��������еĿ�ͷ
        //����1��2��3��4��5 | 2��3��4��5 ���������е������Ӧ����1��ͷ��������2
        //������2��ʱ�����ǿ���ֱ����������Ϊ�Ѿ������������������С������y������
        int x = e->key;
        int y = x - 1;
        HASH_FIND_INT(table, &y, e);
        if (e)
        {
            continue;
        }
        //x����㣬��ʼ����
        y = x;
        do {
            y++;
            HASH_FIND_INT(table, &y, e);

        } while (e);
        //����
        ans = (ans > (y - x)) ? ans : (y - x);

    }
    //�ͷŹ�ϣ��ڵ㣬�����ڴ�й©
    HASH_ITER(hh, table, e, tmp)
    {
        HASH_DEL(table, e);
        free(e);
    }

    return ans;
}