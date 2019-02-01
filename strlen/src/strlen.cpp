#include<stdio.h>
#include<string.h>

int strLen(char *str)
{
    int i = 0;
    while(*(str + i)) {
        i++;
    }
    return i;
}

int strCpy(const char *src, char *dst)
{
    int i = 0;
    while(*(src + i)) {
        *(dst + i) = *(src + i);
        i++;
    }
    *(dst + i) = '\0';
    return 0;
}

int main()
{
    char a[] = "asdfgg";
    char b[20];
    printf ("Str len %s - %d\n", a, strLen(a));
    strCpy(a, b);
    printf ("Copied string %s\n", b);
    return 0;
}
