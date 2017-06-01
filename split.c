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
    return split2(str,token,0);
}

PUBLIC char** split2( char* str, char token, int id )
{
    static int numOfSubStr = 0;
    static char** substring = NULL;
    char* index = str;

    while ( *index )
    {
        if(*index++ == token)
        {
            ++numOfSubStr;
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
        if( id == 0 )
            return NULL;

        substring = (char**) malloc(sizeof(char*) * (id+1) );
        substring[id] = (char*) malloc(sizeof(char)* (index - str)+1 );
        register int i;
        int length = (int) (index - str);
        for( i = 0 ; i < length ; ++i, ++str )
            substring[id][i] = *str;
        substring[id][i] = '\0';
        return NULL;
    }
    return substring;
}

int main(void)
{
    char** substring = split("Daniel Cardoso Leao",' ');

    printf("substring[0]: %s; size: %lu\n",substring[0],strlen(substring[0]));
    printf("substring[1]: %s; size: %lu\n",substring[1],strlen(substring[1]));
    printf("substring[2]: %s; size: %lu\n",substring[2],strlen(substring[2]));

    return 0;
}
