//g++     encodeString.cpp   -o encodeString
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<sys/types.h>
using namespace std;

char* strltrim(char *str)
{
	printf("\nleft trim\n");
        unsigned int p = 0;
        if(str != NULL)
        {
                while(isspace(str[p++]) && p < strlen(str));
                {       if(str[p] == '\0' && isspace(str[p - 1]))
                        str[0] = 0;
                        else if(--p > 0)
                        {
                                printf("str='%s'\np='%d'\nstr+p='%s'\nstrlen(str)='%d'\n",str,p, str + p, strlen(str));
                                printf("strlen(str)='%d'\nstrlen(str+p)='%d'\n",strlen(str),strlen(str+p));
                                strncpy(str, str + p, strlen(str));
                                strcpy(str, str + p);
                                printf("str='%s'\n",(str));
                        }
                }
        }

        return str;
}
char* strrtrim(char *str)
{
	printf("\nright trim\n");
        int p;
        if(str != NULL)
        {
                p = strlen(str) - 1;
                printf("str='%s'\np='%d'\nstr+p='%s'\nstrlen(str)='%d'\n",str,p, str + p, strlen(str));
                while(isspace(str[p]) && --p >= 0);
		{              
			printf("str='%s'\n",(str));
			str[++p] = 0;
			printf("str='%s'\n",(str));
		}
	}
	return str;
}

char* strtrim(char *str)
{
        if(str != NULL)
        {
                str = strltrim(str);
                str = strrtrim(str);
        }

        return str;

}

int main()
{
	char chars[] = "  ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/  ";
	printf("Original data chars ='%s' \n",chars);
	strtrim(chars);
	printf("Modified data chars ='%s' \n",chars);
}
