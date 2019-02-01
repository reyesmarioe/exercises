#include<stdio.h>
#include<string.h>

/*
 * Hash function for chars A-Z, some chars, a - z
 *
 * If char is A, return value is A - A (zero)
 * For B, B - A (1)
 * ...
 */
int hf(char c) {
    return c - 65;
}
 
char recurc(char *str)
{
    // Array used as hash table
    char alpha[100] = {0};
    int l = strlen(str);
    int i;
    int j;


    for (i = 0; i < l; i++) {
        j = hf(*(str + i));
        printf ("letter index %d\n", j);
        // Save a non repeating char in hash table
        if (0 == alpha[j]) {
            alpha[j] = 1;
        } else {
            // Until space for this char is occupied, then we have found the char
            return *(str + i);
        }
    }
    return 0;
}

int main()
{
    char a[] = "asdfgg";
    printf ("recur char %c\n", recurc(a));
    return 0;
}
