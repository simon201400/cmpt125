int strlen(char* str)//这可以吗
{
    int strlen = 0;
    strlen = sizeof(str)/sizeof(char) - 1;
    return strlen;
}

int strlen(char* str)
{
    int strlen = 0;
    while (str[strlen] != 0)
    {
        strlen++;
    }
    return strlen;
}