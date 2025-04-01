#define N 2000

//����ջ�ṹ��30��ʾջ�ڿɴ�Ԫ�ظ�����top��ʾջ��
typedef struct {
    int data[30];
    int top;
}stack;

//��ջ��e��val����data�ڣ�topָʾ��ǰջ��
void push(stack* s, int e)
{
    s->data[(s->top)++] = e;
}

//��ջ
int pop(stack* s)
{
    return s->data[--(s->top)];
}

//�ַ�����ת��������
int string_into_int(char* s)
{
    char val[] = { '\0','\0','\0','\0','\0' };
    int result = 0;

    //isdigit()�ж��ַ��Ƿ���0~9���������ַ�����val[]
    for (int i = 0; isdigit(s[i]); ++i)
    {
        val[i] = s[i];
    }

    //iָʾ���ֳ��ȣ���0��Ҳ������-1
    for (int i = strlen(val) - 1, temp = 1; i >= 0; --i, temp *= 10)
    {
        result += ((val[i] - '0') * temp);
    }
    return result;
}

char* decodeString(char* s) {
    //��������ջ��һ������ջ��һ��λ��ջ
    stack position; position.top = 0;
    stack magnification; magnification.top = 0;

    //resultָ�򴴽�����Ԫ�ص�ַ��rear��β��ָ�루�������������ָ��β��Ԫ�أ�
    char* result = (char*)malloc(sizeof(char) * N);
    char* rear = result;

    //��ʼ����
    for (int i = 0; s[i] != '\0';)
    {
        //�ж��Ƿ�Ϊ����
        if (isdigit(s[i]))
        {
            push(&magnification, string_into_int(&s[i]));
            //��Ϊstring_into_int�Ὣһ���������ַ�ת������Ӧ�����Σ�������while�������ַ�����
            while (isdigit(s[i])) i++;
        }

        //��¼Ҫ�����ַ��Ŀ�ͷ
        else if (s[i] == '[')
        {
            //rear��result ���м����Ԫ�ظ�������¼[���ֵ��±�
            push(&position, rear - result);
            i++;
        }

        //��¼Ҫ�����ַ��Ľ�β
        else if (s[i] == ']')
        {
            //p������ԭ��һ��rear��'['���ֵ��±꣩
            char* p = result + pop(&position);
            //Ҫ���Ƶĳ��ȣ�-1��Ϊ��������ӡһ��
            int count = (rear - p) * (pop(&magnification) - 1);
            for (; count > 0; count--)
            {
                *(rear++) = *(p++);
            }
            i++;
        }

        //û�и��ƴ���Ҫ���������ӡ
        else
        {
            *(rear++) = s[i++];
        }
    }

    //���ص����ַ�����'\0'���ַ��������ı�־
    *rear = '\0';
    return result;
}