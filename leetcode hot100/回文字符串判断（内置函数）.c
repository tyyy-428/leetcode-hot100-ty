bool isPalindrome(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        //Ìø¹ý·Ç×ÖÄ¸Êý×Ö×Ö·û
        if (!isalnum(s[i]))
        {
            i++;
        }
        else if (!isalnum(s[j]))
        {
            j--;
        }

        //ÅÐ¶Ï´óÐ¡Ð´
        else if (tolower(s[i]) == tolower(s[j]))
        {
            i++;
            j--;
        }
        else if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }

    }
    return true;
}