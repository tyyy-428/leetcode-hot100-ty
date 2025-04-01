#define N 2000

//定义栈结构：30表示栈内可存元素个数；top表示栈顶
typedef struct {
    int data[30];
    int top;
}stack;

//进栈，e的val存在data内，top指示当前栈顶
void push(stack* s, int e)
{
    s->data[(s->top)++] = e;
}

//出栈
int pop(stack* s)
{
    return s->data[--(s->top)];
}

//字符整数转换成整型
int string_into_int(char* s)
{
    char val[] = { '\0','\0','\0','\0','\0' };
    int result = 0;

    //isdigit()判断字符是否是0~9，将数字字符存入val[]
    for (int i = 0; isdigit(s[i]); ++i)
    {
        val[i] = s[i];
    }

    //i指示数字长度，‘0’也算所以-1
    for (int i = strlen(val) - 1, temp = 1; i >= 0; --i, temp *= 10)
    {
        result += ((val[i] - '0') * temp);
    }
    return result;
}

char* decodeString(char* s) {
    //创建两个栈，一个数字栈，一个位置栈
    stack position; position.top = 0;
    stack magnification; magnification.top = 0;

    //result指向创建的首元素地址，rear是尾部指针（会随着数组更新指向尾部元素）
    char* result = (char*)malloc(sizeof(char) * N);
    char* rear = result;

    //开始遍历
    for (int i = 0; s[i] != '\0';)
    {
        //判断是否为数字
        if (isdigit(s[i]))
        {
            push(&magnification, string_into_int(&s[i]));
            //因为string_into_int会将一整串数字字符转换成相应的整形，所以用while把数字字符跳过
            while (isdigit(s[i])) i++;
        }

        //记录要复制字符的开头
        else if (s[i] == '[')
        {
            //rear—result 是中间相隔元素个数，记录[出现的下标
            push(&position, rear - result);
            i++;
        }

        //记录要复制字符的结尾
        else if (s[i] == ']')
        {
            //p用来还原第一个rear（'['出现的下标）
            char* p = result + pop(&position);
            //要复制的长度，-1因为他本身被打印一次
            int count = (rear - p) * (pop(&magnification) - 1);
            for (; count > 0; count--)
            {
                *(rear++) = *(p++);
            }
            i++;
        }

        //没有复制次数要求的正常打印
        else
        {
            *(rear++) = s[i++];
        }
    }

    //返回的是字符串，'\0'是字符串结束的标志
    *rear = '\0';
    return result;
}