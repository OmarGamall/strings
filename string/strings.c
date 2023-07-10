#include <stdio.h>
/*Function used to print string elements*/
void string_print(char *str)
{
    char i = 0;
    while (str[i] != 0)
    {
        printf("%c", str[i]);
        i++;
    }
}

/*Function used to scan a string from the user*/
void string_scan(char *str)
{
    int i = 0;
    scanf(" %c", &str[i]);
    while (str[i] != '\n')
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = 0; // insert null character
}

/*Function used to reverse a string from start to end*/
void string_reverse(char *str, char start, char end)
{
    char temp;
    while (end > start)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

/*Function used to compare between two strings */
/*returns: 0 if they are the same
           1 if str1 > str2
          -1 if str1 < str2
*/
/*Note: this functions is  case sensitive */
int string_compare(char *str1, char *str2)
{
    char i = 0;
    for (i = 0; (str2[i] != 0) || (str1[i] != 0); i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    return 0;
}

/*Function used to copy string1 to string2*/
void string_copy(char *source, char *destenation)
{
    int i = 0;
    for (i = 0; source[i]; i++)
    {
        destenation[i] = source[i];
    }
    destenation[i] = '\0'; // insert null
}

int string_length(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char char_to_lower(char x)
{
    if (x >= 'A' && x <= 'Z')
    {
        /*its a capital letter ,,, convert it to small*/
        x = x - 'A' + 'a';
    }
    return x;
}

char char_to_upper(char x)
{
    if (x >= 'a' && x <= 'z')
    {
        /*its a capital letter ,,, convert it to small*/
        x = x - 'a' + 'A';
    }
    return x;
}

/*Function used to convert from integer to string*/
void int_to_string(int num, char *str)
{
    int i = 0, start = 0;
    if (num < 0)
    {
        num = num * (-1);
        start = 1;
        str[i++] = '-';
    }
    else if (num == 0)
    {
        str[i++] = '0';
        str[i] = 0; // insert null
        return;
    }
    while (num > 0)
    {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }
    str[i] = 0; // insert null character
    string_reverse(str, start, i - 1);
}

/*Function used to convert from string to integer (4 btyes)*/
int string_to_int(char *str)
{
    int i = 0, num = 0, j = 0;
    char signSignFlag = 0; // signSignFlag to recognize the negative sign
    if (str[0] == '-')
    {
        i++;
        signSignFlag = 1;
    }
    else if (str[0] == '0')
    {
        return 0;
    }
    while (str[i])
    {
        num = num * 10;
        num = num + ((str[i++] - '0'));
    }
    if (signSignFlag == 1)
    {
        return (num * (-1));
    }
    else
    {
        return num;
    }
}

/*Function used to convert from float to string*/
void float_to_string(float num, char reslution, char *str)
{
    char SignFlag = 0, start = 0;
    if (num < 0)
    {
        num = num * (-1);
        SignFlag = 1;
    }
    int int_part = num;              // integer part of the number
    float f_part = (num - int_part); // float part of the number
    int f;                           // float part of the number stored in int type
    char float_point_index;
    int i = 0; // counter
    // variable reslution is the no of number will be printed after the float point
    switch (reslution)
    {
    case 1:
        f = f_part * 10;
        break;

    case 2:
        f = f_part * 100;
        break;

    case 3:
        f = f_part * 1000;
        break;

    case 4:
        f = f_part * 10000;
        break;
    }
    if (SignFlag == 1)
    {
        str[0] = '-';
        i++;
        start = 1;
    }
    else
    {
        start = 0;
    }
    // serve int part
    while (int_part != 0)
    {
        str[i++] = (int_part % 10) + '0';
        int_part = int_part / 10;
    }
    float_point_index = i;
    string_reverse(str, start, i - 1);
    str[i++] = '.'; // insert flaoting point
    // serve the float part
    while (f != 0)
    {
        str[i++] = (f % 10) + '0';
        f = f / 10;
    }
    str[i] = 0; // insert null end of the string
    string_reverse(str, float_point_index + 1, string_length(str) - 1);
}

/*Function used to convert an int decimal number into a Hex string*/
char *int_to_Hex(int num)
{
    const char HexTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    static char HexStr[10] = {"\0"};
    int i = 0;
    unsigned int Mirror_num = num; // For negative integers, two’s complement method is used.
    if (num == 0)
    {
        HexStr[i++] = '0';
        HexStr[i] = 0; // insert null
        return HexStr;
    }
    while (Mirror_num)
    {
        HexStr[i++] = HexTable[Mirror_num % 16];
        Mirror_num = Mirror_num / 16;
    }
    // insert null character
    HexStr[i] = 0;
    string_reverse(HexStr, 0, i - 1);
    return HexStr;
}

/*function used to remove spaces from a string and returns the new string length*/
/*O(n) time space*/
int removeSpaces(char *str)
{
    int i = 0; // pointer to next position where a non-space character should be copied
    int j = 0; // pointer to the current character being examined
    int c = 0; // index of the current character in the string
    while (str[c])
    {
        if (str[c] == ' ')
        {
            j++; // skip space character
        }
        else
        {
            str[i] = str[j];
            i++;
            j++;
        }
        c++;
    }
    // insert NULL character
    str[i] = '\0';
    return i; // new length
}

/*Function used to erase a character from a string
@Inputs:
  1-str:   pointer to the string
  2-pos:   position of the character (start from index 0)
  3-n:     Number of characters to be deleted
*/
void str_erase_char(char* str, unsigned int pos, unsigned int n)
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++, j++)
    {
        if (i == pos)
        {
            i = i + n;
        }
        str[j] = str[i];
    }
    str[j] = 0; // insert Null character
}
int arr[] = {2,5,3,2};

/*return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
int strStr(char *haystack, char *needle)
{
    const int n = strlen(haystack);
    const int m = strlen(needle);
    int i = 0;
    int j = 0;
    for (i = 0; i < (n - m + 1); i++)
    {
        for (j = 0; needle[j]; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break; // break the inner loop
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

