// NonChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<stdio.h>
#include<string.h>

typedef struct {
	int found;
	int position;
}CHARS;

char *lsnc(char *str)
{
	char *ptrStrScanner = NULL;
	char *ptrScannerEnd = NULL;
	char *subStr = NULL;
	int strIndex = 0;
	int subStrLen = 0;
	int maxStrLen = 0;
	CHARS foundChars[256] = { -1, -1 };
	int totalChars = 256;
	int currChar = 0;
	int prevChar = 0;
	int increment = 0;
	int overwriteStr = 0;
	int processChars = 0;
	int recentRegression = 0;

	memset(foundChars, -1, sizeof(CHARS) * 256);
	subStr = str;
	ptrStrScanner = str;
	ptrScannerEnd = str;

	if (0 == strlen(str)) {
		return 0;
	}
	while (*(str + strIndex)) {
		currChar = *(str + strIndex);
		++processChars;
		if (-1 == foundChars[currChar].found) {
			++ptrScannerEnd;
			foundChars[currChar].found = 1;
			foundChars[currChar].position = processChars;
		}
		else {
			subStrLen = ptrScannerEnd - ptrStrScanner;
			if (prevChar != currChar)
			{
				increment = foundChars[currChar].position;
				foundChars[currChar].position = processChars;

				if (subStrLen > maxStrLen) {
					subStr = ptrStrScanner;
					maxStrLen = ptrScannerEnd - ptrStrScanner;
				}

				if (recentRegression < increment) {
					ptrStrScanner = str + increment;
					recentRegression = increment;
				}
				//++ptrScannerEnd;
				

			}
			else {
				increment = foundChars[currChar].position;
				foundChars[currChar].position = processChars;
				if (subStrLen > maxStrLen) {
					subStr = ptrStrScanner;
					maxStrLen = ptrScannerEnd - ptrStrScanner;
				}
				else {
					subStrLen = 1;
				}
				
				ptrStrScanner = str + increment;
				//++ptrScannerEnd;

				memset(foundChars, -1, sizeof(CHARS) * 256);
				foundChars[currChar].found = 1;
				foundChars[currChar].position = processChars;
			}
			++ptrScannerEnd;
		}
		++strIndex;
		prevChar = currChar;
	}

	
	if ((ptrScannerEnd - ptrStrScanner) > maxStrLen) {
		maxStrLen = ptrScannerEnd - ptrStrScanner;
		subStr = ptrStrScanner;
	}
	*(subStr + maxStrLen + 1) = 0;
	return subStr;
}


int main()
{
	char str[256];
	char *s = NULL;
#if 1
	while (1) {
		printf("Enter chars sequence : \n");
		//scanf_s("%s", str, sizeof(str));
		fgets(str, sizeof(str), stdin);

		//printf("strlen is %d - %s", strlen(str), str);
		if (1 < strlen(str)) {
			str[strcspn(str, "\n\r")] = 0;
			printf("Longes substr - [ %s ]\n", lsnc(str));
		}
		else {
			break;
		}
	}



#endif
}
