/*le     xsh_palindrome.c
 * @provides xsh_help
 *  *
 *   * $Id: xsh_help.c 226 2007-07-12 01:18:27Z mschul $
 *    */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <kernel.h>
#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

command xsh_palindrome(ushort stdin, ushort stdout, ushort stderr,
                 ushort nargs, char *args[])
{
    char string1[30];
    int i, length;
    int flag = 0;
    
   printf("Enter a string:");
   scanf("%s", string1);
    
    length = strlen(string1);
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
	   }
	}
    
    if (flag) {
       printf("%s is not a palindrome \n", string1);
    }    
    else {
       printf("%s is a palindrome\n", string1);
}    
	return OK;
}
