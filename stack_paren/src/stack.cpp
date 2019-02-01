/*
 * Simple stack implementation
 *
 *      bottom            top
 *      +---+---+---+---+---+
 *      | 4 | 3 | 9 | 1 | 3 |
 *      +---+---+---+---+---+
 *
 *
 * This is a LIFO (Last In, Firt Out) data structure
 *
 * push 
 *      data enters on the top of the stack
 *
 * pop 
 *      data leaves on the top of the stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
#ifdef DEBUG
#define VERIFY(x)       if (!(x)) { \
                            nErr = -1; \
                            goto bail; \
                        }
#else
#define VERIFY(x)       (void)(x);
#endif
#endif

#define VERIFY(x)       if (!(x)) { \
                            nErr = -1; \
                            goto bail; \
                        }
typedef struct node {
   char c;
   struct node *pNext;
} STACK;

   
/*
 * Very simple stack implementation. 
 * Adds node to the top of the stack.
 *
 * Insertion performance is O(1)
 */
int push(STACK **top, char c)
{
    STACK *newNode = NULL;
    int nErr = 0;

    VERIFY(NULL != (newNode = (STACK*)malloc(sizeof(STACK)))); 
    newNode->c = c;
    newNode->pNext = NULL;

    //printf ("Push %c\n", c);
    if (*top) {
        newNode->pNext = *top;
        *top = newNode;
    } else {
        /*
         * At this point, the head pointer is NULL so here we have it point
         * to the first node
         */
        *top = newNode;
        (*top)->pNext = NULL;
    }

bail:
    if (nErr) {
        printf ("Error \n");
    }
    return nErr;
}

int pop(STACK **top, char c)
{
    STACK *currNode = NULL;
    int nErr = 0;

    //printf ("IN POP\n");

    // Make sure we have some data to dequeue
    VERIFY(*top != NULL);

    currNode = *top;
    //printf ("currNode->c %c == %c\n", currNode->c, c);
    //printf ("value %d\n", c - currNode->c);
    if ( (1 == (c - currNode->c)) ||
         (2 == (c - currNode->c) )) {
        //printf ("pop %c\n", currNode->c);
        *top = currNode->pNext;
        free(currNode);
        currNode = NULL;
    } else {
        return -1;
    }

bail:
    if (nErr) {
        printf ("List is empty\n");
    }

    return nErr;
}

int balance_symbols(STACK **top, char *str)
{
    int strLen = 0;
    char c;
    int nErr = 0;
    int i = 0;

    VERIFY(NULL != str);
    strLen = strlen(str);
    //printf ("String is %s = %d\n", str, strLen);

    while (i < strLen) {
        c = *(str + i);
        //printf ("iters %d\n", i);
        switch (c) {
            case '(':
            case '{':
            case '[':
                //printf ("pushing %c\n", c);
                push(top, c);
                break;
            case ')':
            case '}':
            case ']':
                //printf ("popping %c\n", c);
                VERIFY(0 == pop(top, c));
                break;
            default:
                break;
        }
        i++;
    }

    if (NULL == *top) {
        nErr = 0;
    } else {
        nErr = -1;
    }

bail:
    return nErr;
}


void print_list(STACK *ph)
{ 
    STACK *tmpFront = ph;
    if (NULL == tmpFront) {
        printf ("List is empty\n");
        return;
    }
    while (tmpFront) {
        printf ("%c ", tmpFront->c);
        tmpFront = tmpFront->pNext;
    }
    printf ("\n\n");
}


int main (int argc, char *argv[])
{
    STACK *pHead = NULL;
    char symString [100];

    printf ("Test string : ");
    scanf("%s", symString);
    if (!balance_symbols(&pHead, symString)) {
        printf ("\tBalanced\n");
    } else {
        printf ("\tNOT balanced\n");
    }
    
    return 0;
}
