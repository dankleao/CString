//
// Created by Daniel Cardoso on 31/05/17.
//

#include <stdio.h>
#include <string.h>
#include "def.h"

PUBLIC char** split(char*,char);
PUBLIC char** split2(char*,char,int);

PUBLIC char** split( char* str, char token )
{
    if( strlen(str) == 0 ) 
        return NULL;
        
    return split2(str,token,0);
}

PUBLIC char** split2( char* str, char token, int id )
{
    static char** substring = NULL;
    char* index = str;

    while ( *index )
    {
        if(*index++ == token)
        {
            split2(index,token, (id + 1));
            substring[id] = (char*) malloc(sizeof(char)* ((index - str)) );
            register int i;
            int length = (int) ((index - str)-1);
            for( i = 0 ; i < length ; ++i )
                substring[id][i] = *str++;
            substring[id][i] = '\0';
            break;
        }
    }

    if( *index == '\0' )
    {
        substring = (char**) malloc(sizeof(char*) * (id+1) );
        substring[id] = (char*) malloc(sizeof(char)* (index - str)+1 );
        register int i;
        int length = (int) (index - str);
        for( i = 0 ; i < length ; ++i, ++str )
            substring[id][i] = *str;
        substring[id][i] = '\0';
        return substring;
    }
    return substring;
}

int main(void)
{
    
    printf("\nTests...\n\n");
    char** substring = split("Daniel Cardoso Leao",' ');
    printf("substring[0]: %s; size: %lu\n",substring[0],strlen(substring[0]));
    printf("substring[1]: %s; size: %lu\n",substring[1],strlen(substring[1]));
    printf("substring[2]: %s; size: %lu\n",substring[2],strlen(substring[2]));
    printf("\n");
    
    char** substring2 = split("Test.c",'*');
    printf("substring2[0]: %s; size: %lu\n",substring2[0],strlen(substring2[0]));
    printf("\n");

    char** substring3 = split("",' ');
    if( substring3 == NULL )
        printf("Empty String!\n");
    printf("\n");

    char** substring4 = split("/Users/Daniel/Desktop/CLanguage/CString",'/');
    printf("substring4[0]: %s; size: %lu\n",substring4[0],strlen(substring4[0]));
    printf("substring4[1]: %s; size: %lu\n",substring4[1],strlen(substring4[1]));
    printf("substring4[2]: %s; size: %lu\n",substring4[2],strlen(substring4[2]));
    printf("substring4[3]: %s; size: %lu\n",substring4[3],strlen(substring4[3]));
    printf("substring4[4]: %s; size: %lu\n",substring4[4],strlen(substring4[4]));
    printf("substring4[5]: %s; size: %lu\n",substring4[5],strlen(substring4[5]));
    printf("\n");
    
    char** substring5 = split("www.google.com.br",'.');
    printf("substring5[0]: %s; size: %lu\n",substring5[0],strlen(substring5[0]));
    printf("substring5[1]: %s; size: %lu\n",substring5[1],strlen(substring5[1]));
    printf("substring5[2]: %s; size: %lu\n",substring5[2],strlen(substring5[2]));
    printf("substring5[3]: %s; size: %lu\n",substring5[3],strlen(substring5[3]));
    printf("\n");
    
    return 0;
}
