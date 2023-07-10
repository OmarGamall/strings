#include <stdio.h>
#include <stdlib.h>
#include "string/strings.h"
/*Test string functions*/
extern int arr[];
int main()
{
    char str[10] = {"\0"};
    //string_copy("HELLO\n",str);
    //string_print(str);
    //string_scan(str);
    //printf("%d",string_to_int("100"));
    //int_to_string(-700,str);
    float_to_string(3.50,3,str);
    string_print(str);
    printf("\n%d",sizeof(arr));
    //printf("\n%d",string_len("Omar"));
    return 0;
}