#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include <string.h>
/*
Function that return void pointer, its mission is to check if the char c is found in the str or not
str --> address of the memory block to search in it
c   --> the element to search about 
n   --> number of bytes to search in starting from the address of str
if the c is found it will return the string starting from the target element until the given length n
if it is not found the function will return null
 */
void *my_memchr(const void *str, int c, size_t n)
{
    unsigned int iterator = 0;   // Iterator for the while loop to search in the entire string
    unsigned int flag = 0;       // Flag to check the presence of the element c
    void *ptr = NULL;            /* definition to a ptr and assign it to NULL to allocate the target memory block from the source memory block
                                   if the element is found */
    while (iterator < n)
    {
        if (*(char*)(str+iterator) == c)
        {
            flag = 1;
            break;
        }
        else
        {

        }
        iterator++;
    }
    if (flag == 0)
    {
        ptr = NULL;
    }
    else
    {
        ptr = (char*)(str + iterator);      // Allocating the target memory block to the above defined pointer ptr once the element c is found.
    }
    return ptr;                             // Make typecasting of type char pointer to return the string
}

/*
Function to compare the first n bytes between two memory blocks str1 and str2 

if Return value < 0 then it indicates str1 is less than str2.

if Return value > 0 then it indicates str2 is less than str1.

if Return value = 0 then it indicates str1 is equal to str2.
*/
//Done
int my_memcmp(const void *str1 , const void *str2, size_t Length)
{
    signed int Return_state = 0; //represents str1 is equivalent to the str2
    // applying the typecasting method to access the pointer and make changes
    unsigned char *Tempstr1 = (unsigned char *)str1;
    unsigned char *Tempstr2 = (unsigned char *)str2;

    //Validation step
    if ((NULL == str1) || (NULL == str2))
    {
        printf("Function Failed due to NULL Pointer !!\n");
    }
    else
    {
        if (str1 == str2)
        {
            Return_state = 0;
        }
        else
        {
            while (Length)
            {
                if(*Tempstr1 != *Tempstr2)
                {
                    Return_state = (*Tempstr1 < *Tempstr2) ? -1 : 1;
                    break;
                }
                else
                {
                    Length--;
                    Tempstr1++;
                    Tempstr2++;
                }
            
            
            }
        }
    }

    return Return_state;
    
}

//Done
/*Funtion to copy Length characters from memory area SrcAddress to memory area DestAddress.*/
void *my_memcpy(void *DestAddress, const void *SrcAddress, size_t Length)
{
    // Initializing two local pointer of type unsigned char to point at the DestAddress and SrcAddress consequently
    unsigned char *TempDestAddress = DestAddress;
    unsigned char *TempSrcAddress  = (unsigned char *)SrcAddress;
    if ((NULL == DestAddress) || (NULL == SrcAddress))
    {
        printf("my_memcpy failed because DestAddress or SrcAddress is NULL pointer \n");
    }
    else
    {
        while (Length)
        {
            *TempDestAddress++ = *TempSrcAddress++;
            Length--;
        }
    }
    return DestAddress;
}

/*
  @brief: used to copy a block memory from one location to another. Typically, this function state the count bytes of data 
  from a source location to the destination.
  
  it is better than my_memcpy in handling the overlapping memory my_memcpy failures depend on the order of the overlap
  Examples for cases of overlapping memory: 
  1-    char str[] = "Start stop";
        dest    -->  [---]
        src     -->     [--]
        printf("%s\n",str);

        my_memcpy(str, str+2, 3*sizeof(char));
        printf("%s\n",str);*/
   
void *my_memmove(void *DestAddress, const void *SrcAddress, size_t Length)
{
    unsigned char *TempDest = DestAddress;
    unsigned char *TempSrc = (unsigned char *)SrcAddress;
    unsigned char *TempBfr = (unsigned char *)malloc(sizeof(TempDest[0]) * Length);

    if (NULL == TempBfr)
    {
        printf("Function Failed due to a NULL pointer !!\n");
    }   
    else
    {
        my_memcpy(TempBfr,TempSrc,Length);
        my_memcpy(TempDest,TempBfr,Length);
    }
    free(TempBfr);
    
}

/*copies the character Value (an unsigned char) to the first Length characters of the string pointed to, by the argument 
StrAddress.*/
void *my_memset(void *StrAddress, int Value, size_t Length)
{
    unsigned int iterator = 0;
    unsigned char *TempStrAddress = StrAddress;
    if ((NULL == StrAddress))
    {
        printf("my_strcat Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }

    else
    {
        for (iterator = 0 ; iterator < Length ; iterator++)
        {
            TempStrAddress[iterator] = Value;     
        }
    }
    return StrAddress;
}
/*
    @brief: accepts two pointer variable as parameters(say dest, src) and, appends the string pointed to by src to 
    the end of the string pointed to by dest. This function only concatenates the string data type. We cannot use any 
    other data types such int, float, char, etc.


*/
char *my_strcat(char *DestAddress, const char *SrcAddress)
{
    unsigned char *TempDestAddress = DestAddress;
    unsigned char *TempSrcAddress  = (unsigned char *)SrcAddress;
    
    if ((NULL == DestAddress) || (NULL == SrcAddress))
    {
        printf("my_strcat Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    
    else
    {
        while (*TempDestAddress != '\0')
        {
            TempDestAddress++;
        }

        while (*TempSrcAddress != '\0')
        {
            *(TempDestAddress++) = *(TempSrcAddress++);
        }
    }
    *TempDestAddress = '\0';

    return DestAddress;
}
/*
    @brief: takes three variable as parameters which appends the string pointed to by src to the end of
     the string pointed to by dest up to n characters long.

    Below are some key points that highlight its importance −
      *  It prevent the buffer overflow
      *  It control over string size.
      *  This function safely handle the string.
      *  It maintain the integrity and robustness of software application.
*/
char *my_strncat(char *DestAddress, const char *SrcAddress, size_t Length)
{
    unsigned char *TempDestAddress = DestAddress;
    unsigned char *TempSrcAddress  = (unsigned char *)SrcAddress;
    
    if ((NULL == DestAddress) || (NULL == SrcAddress))
    {
        printf("my_strcat Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    
    else
    {
        size_t DestLenght = my_strlen(DestAddress);
        size_t iterator = 0;
        
        for (iterator = 0 ; iterator < Length; iterator++)
        {
            TempDestAddress[DestLenght+iterator] = TempSrcAddress[iterator];
        }
        
        TempDestAddress[DestLenght+iterator] = '\0';
        
    }
    
    return DestAddress;
}

/*
@brief:
refer to first occurence of a character from a given string. This function operate the task of null characters(\0) or
null-ended string. This function is useful in a variety of text processing tasks where user need to locate a particular character.
*/
char *my_strchr(const char *StrAddress, int Character)
{
    unsigned char *TempStrAddress = (unsigned char *)StrAddress;
    unsigned int flag = 0;

    if (NULL == StrAddress)
    {
        printf("my_strchr Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {
        while (*TempStrAddress != '\0')
        {
            if (*TempStrAddress == Character)
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            TempStrAddress++;
        }
        if (flag == 1)
        {
            TempStrAddress = NULL;
        }
        else
        {

        }
    }   

    return TempStrAddress;
}

/**
 * @brief: compare two strings. It checks each character in the string one by one until it finds a difference or reaches 
 * the end of the one string. Additionally, the strings comparison is based on ASCII values.
 * **********************************************************************************
 * 
 * StrAddress1 − This is the first string to be compared.
 * StrAddress2 − This is the second string to be compared.
 * 
 * **********************************************************************************
 * 
 * if Return value < 0 then it indicates StrAddress1 is less than StrAddress2.
 * if Return value > 0 then it indicates StrAddress2 is less than StrAddress1.
 * if Return value = 0 then it indicates StrAddress1 is equal to StrAddress2.
 * **********************************************************************************

 */

int my_strcmp(const char *StrAddress1, const char *StrAddress2)
{
    signed int Res = 0;             //represents str1 is equivalent to the str2
    unsigned char *TempStrAddress1 = (unsigned char *)StrAddress1;
    unsigned char *TempStrAddress2 = (unsigned char *)StrAddress2;
    if ((NULL == StrAddress1) || (NULL == StrAddress2))
    {
        printf("my_strcmp Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {    
        
        if (StrAddress1 == StrAddress2)
        {
            Res = 0;
        }
        else
        {
            while ((*TempStrAddress1 != '\0') && (*TempStrAddress2 != '\0'))
            {
                
                
                if (*StrAddress1 != *StrAddress2) 
                {
                    Res = (*StrAddress1 < *StrAddress2) ? -1 : 1;
                    break;
                }
                else
                {
                    TempStrAddress1++;
                    TempStrAddress2++;
                }
            }
        }
          
    }

    return Res;
}

/**
 * my_strncmp compares at most the first Length bytes of StrAddress1 and StrAddress2.
 * **********************************************************************************
 * 
 * StrAddress1 − This is the first string to be compared.

 * StrAddress2 − This is the second string to be compared.

 * Length − The maximum number of characters to be compared.

 ************************************************************************************
 * if Return value < 0 then it indicates StrAddress1 is less than StrAddress2.
 * if Return value > 0 then it indicates StrAddress2 is less than StrAddress1.
 * if Return value = 0 then it indicates StrAddress1 is equal to StrAddress2.
 * **********************************************************************************
*/
int my_strncmp(const char *StrAddress1, const char *StrAddress2, size_t Length)
{
    signed int Res = 0;                //represents str1 is equivalent to the str2
    unsigned char *TempStrAddress1 = (unsigned char *)StrAddress1;
    unsigned char *TempStrAddress2 = (unsigned char *)StrAddress2;
    if ((NULL == StrAddress1) || (NULL == StrAddress2))
    {
        printf("my_strcmp Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {    
        
        if (StrAddress1 == StrAddress2)
        {
            Res = 0;
        }
        else
        {
            while (Length)
            {
                
                if (*StrAddress1 != *StrAddress2) 
                {
                    Res = (*StrAddress1 < *StrAddress2) ? -1 : 1;
                    break;
                }
                else
                {
                    TempStrAddress1++;
                    TempStrAddress2++;
                    Length--;
                }
            }
        }
          
    }
    return Res;
}
/**
 * @brief: two pointer variable which compares two strings say(str1 to str2). The result is dependent on the LC_COLLATE setting 
 * of the location.
 * Its ability is to compare the strings in locale manner. The string comparison functions, such as strcmp, 
 * perform a simple byte-to-byte comparison, while strcoll() takes into account the current locale settings. 
 * This allows for string comparison based on important rules such as alphabetical order and case sensitivity.
 * StrAddress1 − This is the first string to be compared.

 * StrAddress2 − This is the second string to be compared.

 * Length − The maximum number of characters to be compared.

 ************************************************************************************
 * if Res < 0 then it indicates StrAddress1 is less than StrAddress2.
 * if Res > 0 then it indicates StrAddress2 is less than StrAddress1.
 * if Res = 0 then it indicates StrAddress1 is equal to StrAddress2.
 * **********************************************************************************
 * 
 */

int my_strcoll(const char *StrAddress1, const char *StrAddress2)
{
    int Res = 0;                          //represents str1 is equivalent to the str2
    unsigned int iterator = 0;
    unsigned int Length = (my_strlen(StrAddress1) < my_strlen(StrAddress1)) ? strlen(StrAddress1) : strlen(StrAddress2);
    unsigned char *TempStrAddress1 = (unsigned char *)StrAddress1;
    unsigned char *TempStrAddress2 = (unsigned char *)StrAddress2;

    for (iterator = 0 ; iterator <= Length ; iterator++)
    {
        if (StrAddress1 == StrAddress2)
        {
            Res = 0;
            break;
        }
        else
        {
            // Once a difference is located, it will break the loop and return the difference value according to ASCII
            if (TempStrAddress1[iterator] != TempStrAddress2[iterator])
            {
                Res = (TempStrAddress1[iterator] - TempStrAddress2[iterator]);
                break;
            }
            else
            {

            }
            
        }
        
    }
    return Res;
}

char *my_strcpy(char *DestAddress, const char *SrcAddress)
{
    unsigned char *TempSrcAddress = (unsigned char *)SrcAddress;
    unsigned char *TempDestAddress = DestAddress;
    while (*TempSrcAddress != '\0')
    {
        *TempDestAddress= *TempSrcAddress;
        TempDestAddress++;
        TempSrcAddress++;
    }
    *TempDestAddress = '\0';
    return DestAddress;
}
char *my_strncpy(char *DestAddress, const char *SrcAddress, size_t Length)
{
    unsigned char *TempSrcAddress = (unsigned char *)SrcAddress;
    unsigned char *TempDestAddress = DestAddress;
    while (Length--)
    {
        *TempDestAddress++= *TempSrcAddress++;
    }
    *TempDestAddress = '\0';
    return DestAddress;
}
/**
 * my_strcspn calculates the length of the initial segment of str1, which consists entirely of characters not in str2.
 * **********************************************************************************************************************
 * 
 * StrAddress1 − This is the main C string to be scanned.
 * StrAddress2 − This is the string containing a list of characters to match in str1.
 * 
 * **********************************************************************************************************************
 * This function returns the number of characters in the initial segment of string str1 which are not in the string str2.
*/
size_t my_strcspn(const char *StrAddress1, const char *StrAddress2)
{
    unsigned int strilen = my_strlen(StrAddress2);
    unsigned int iter = 0;
    unsigned int Len = 0;
    unsigned int flag =0;
    unsigned char *TempStrAddress1 = (unsigned char *)StrAddress1;
    unsigned char *TempStrAddress2 = (unsigned char *)StrAddress2;

    if ((NULL == StrAddress1) || (NULL == StrAddress2))
    {
        printf("my_strcspn Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {
        while (*TempStrAddress1 != '\0')
        {
            for (iter = 0 ; iter < strilen ; iter++)
            {
                if (*TempStrAddress1 == TempStrAddress2[iter])
                {
                    flag = 1;
                    break;
                }
                else
                {
                    
                }
            }
            TempStrAddress1++;
            if (flag == 1)
            {
                break;
            }
            Len ++;
        }  
    }
    return Len;
}


/**
 * my_strlen computes the length of the string str up to, but not including the terminating null character.
 * ********************************************************************************************************
 * 
 * Str − This is the string whose length is to be found.
 * 
 * ********************************************************************************************************
 * This function returns the length of string.

*/
size_t my_strlen(const char *Str)
{
    unsigned int Len = 0;
    while (*Str != '\0')
    {
        Len++;
        Str++;
    }
    return Len;
}

/**
 * finds the first character in the string StrAddress1 that matches any character specified in StrAddress2. 
 * This does not include the terminating null-characters.
 * ********************************************************************************************************
 * 
 * StrAddress1 − This is the C string to be scanned.
 * StrAddress2 − This is the C string containing the characters to match.
 * 
 * ********************************************************************************************************
 * 
 * This function returns a pointer to the character in StrAddress1 that matches one of the characters in This function 
 * returns a pointer to the character in StrAddress1 that matches one of the characters in StrAddress2, or NULL 
 * if no such character is found., or NULL if no such character is found.
 * 
 * 
*/
char *my_strpbrk(const char *StrAddress1, const char *StrAddress2)
{
    unsigned char *C = NULL;
    unsigned int iter1 = 0;
    unsigned int iter2 = 0;
    unsigned char *TempStrAddress1 = (unsigned char *)StrAddress1;
    unsigned char *TempStrAddress2 = (unsigned char *)StrAddress2;
    unsigned int flag = 0;

    if ((NULL == StrAddress1) || (NULL == StrAddress2))
    {
        printf("my_strpbrk Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {
        for (iter1 = 0 ; iter1 < my_strlen(TempStrAddress1) ; iter1++)
        {
            for (iter2 = 0 ; iter2 < my_strlen(TempStrAddress2) ; iter2++)
            {
                if (TempStrAddress1[iter1] == TempStrAddress2[iter2])
                {
                    C = &(TempStrAddress1[iter1]);
                    flag = 1;
                    break;
                }
                else
                {

                }
            }              
            TempStrAddress1 = (unsigned char *)StrAddress1;
            if (flag == 1)
            {
                break;
            }
            else
            {

            }
            
        }
    }
    return C;
}

/**
 * searches for the last occurrence of the character C (an unsigned char) in the string pointed to, by the argument Str.
 * ****************************************************************************************************************************
 * 
 * Str − This is the C string.
 * C − This is the character to be located. It is passed as its int promotion, but it is internally converted back to char.
 * 
 * ****************************************************************************************************************************
 * This function returns a pointer to the last occurrence of character in Str.
 * If the value is not found, the function returns a null pointer.
*/
char *my_strrchr(const char *Str, int C)
{
    unsigned char *TempStr1 = (unsigned char *)Str;
    unsigned char *TempStr11 = NULL;
    if (NULL == Str)
    {
        printf("my_strrchr Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {
        while (*TempStr1 != '\0')
        {
            if (C == *TempStr1)
            {
                TempStr11 = TempStr1;
            }
            else
            {
                
            }
            TempStr1++;
        }
    }
    return TempStr11;
    
}

/**
 * calculates the length of the initial segment of Str1 which consists entirely of characters in Str2
 * ************************************************************************************************************************
 * 
 * Str1 − This is the main C string to be scanned.
 * Str2 − This is the string containing the list of characters to match in str1.
 * 
 * ************************************************************************************************************************
 * This function returns the number of characters in the initial segment of Str1 which consist only of characters from Str2.
*/
size_t my_strspn(const char *Str1, const char *Str2)
{
    unsigned int Initial_Len = 0;
    unsigned int iter1 = 0;
    unsigned int iter2 = 0;
    unsigned int Str1Len = my_strlen(Str1);
    unsigned int Str2Len = my_strlen(Str2);
    unsigned int flag = 0;
    unsigned char *TempStr1 = (unsigned char *)Str1;
    unsigned char *TempStr2 = (unsigned char *)Str2;

    if ((NULL == Str1) || (NULL == Str2))
    {
        printf("my_strspn Failed because one of DestAddress or SrcAddress is NULL Pointer \n");
    }
    else
    {
        for (iter1 = 0 ; iter1 < Str1Len ; iter1++)
        {
            flag = 0;
            for (iter2 = 0 ; iter2 < Str2Len ; iter2++)
            {
                if (TempStr2[iter2] == TempStr1[iter1])
                {
                    flag = 1; //indicating of existence of matching between characters in Str2 and the initial segment in Str1
                    break;
                }
                else{}   
            }
            if (flag == 0)
            {
                break;
            }
            else{Initial_Len++;}
            
        }
    }
    return Initial_Len;

}

/**
 * @brief Finds the first occurrence of a substring within a larger string.
 *
 * The function searches for the first occurrence of the substring `Needle` within the string `Haystack`.
 * If the substring is found, it returns a pointer to the beginning of the substring in `Haystack`.
 * If the substring is not found, it returns `NULL`.
 *
 * @param Haystack The string to be searched.
 * @param Needle The substring to search for.
 * @return A pointer to the first occurrence of `Needle` in `Haystack`, or `NULL` if `Needle` is not found.
 */
char *my_strstr(const char *Haystack, const char *Needle)
{
    unsigned char *C = NULL;
    unsigned int iter1 = 0;
    unsigned int iter2 = 0;
    unsigned int HayLen = my_strlen(Haystack);
    unsigned int NeedLen = my_strlen(Needle);
    unsigned int start = 0;
    unsigned char *TempHaystack = (unsigned char *)Haystack;
    unsigned char *TempNeedle = (unsigned char *)Needle;

    // Check for NULL pointers
    if ((NULL == Haystack) || (NULL == Needle))
    {
        printf("my_strstr Failed because one of Haystack or Needle is NULL Pointer \n");
        return NULL;
    }

    // Loop through the Haystack string
    for (iter1 = 0; iter1 < HayLen; iter1++)
    {
        // Check if the current character matches the first character of Needle
        if (TempHaystack[iter1] == *TempNeedle)
        {
            unsigned int Tempiter1 = iter1;
            start = Tempiter1;

            // Check the subsequent characters for a full match
            for (iter2 = 0; iter2 < NeedLen; iter2++)
            {
                if (TempNeedle[iter2] != TempHaystack[Tempiter1])
                {
                    break;
                }
                else{}
                Tempiter1++;
            }

            // If the full substring matches, return the starting pointer
            if (iter2 == NeedLen)
            {
                C = &(TempHaystack[start]);
                return C;
            }
            else{}
        }
    }

    // If no match is found, return NULL
    return NULL;
}

char *my_strtok(char *s, const char *delim)
{
    static char *olds;
    char *token;

    if (s == NULL)
        s = olds;

    /* Scan leading delimiters.  */
    s += strspn(s, delim);

    /* if *s points to the null byte \0, that means
        we have reached the end of the string and
        we return NULL
    */
    if (*s == '\0')
    {
        olds = s;
        return (NULL);
    }

    /* Find the end of the token.  */
    token = s;
    s = strpbrk(token, delim);
    if (s == NULL)
        /* This token finishes the string.  */
        olds = strchr(token, '\0');
    else
    {
        /* Terminate the token and make OLDS point past it.  */
        *s = '\0';
        olds = s + 1;
    }
    return (token);      
}


size_t my_strxfrm(char *dest, const char *src, size_t n)
{

}