bool isValid(char* s) {
    //建立一个映射表，用来存储配对的括号值
    char chart[128] = { 0 };
    chart[')'] = '(';
    chart[']'] = '[';
    chart['}'] = '{';

    //初始化栈顶，用s作为栈；
    int top = 0;
    int i = 0;

    //开始遍历，如果是左括号，入栈；
    //如果是右括号，判断：如果此时栈顶为空，说明没有与之配对的括号，返回false
    //不为空，则进行出栈指令，如果与映射表对应值不匹配，说明类型不对，返回false
    //（--top）用于寻找配对的括号
    for (i = 0; s[i]; i++)
    {
        char c = s[i];
        if (chart[c] == 0)
        {
            s[top++] = s[i];
        }
        else if (top == 0 || s[--top] != chart[c])
        {
            return false;
        }
    }
    return top == 0;
}