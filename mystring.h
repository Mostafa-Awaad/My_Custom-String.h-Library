#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#define size_t unsigned int

void *my_memchr(const void *str, int c, size_t n);
int my_memcmp(const void *str1, const void *str2, size_t Length);
void *my_memcpy(void *DestAddress, const void *SrcAddress, size_t Length);
void *my_memmove(void *DestAddress, const void *SrcAddress, size_t Length);
void *my_memset(void *StrAddress, int Value, size_t Length);
char *my_strcat(char *DestAddress, const char *SrcAddress);
char *my_strncat(char *DestAddress, const char *SrcAddress, size_t Length);
char *my_strchr(const char *StrAddress, int Character);
int my_strcmp(const char *StrAddress1, const char *StrAddress2);
int my_strncmp(const char *StrAddress1, const char *StrAddress2, size_t Length);
int my_strcoll(const char *StrAddress1, const char *StrAddress2);
char *my_strcpy(char *DestAddress, const char *SrcAddress);
char *my_strncpy(char *DestAddress, const char *SrcAddress, size_t Length);
size_t my_strcspn(const char *StrAddress1, const char *StrAddress2);
char *my_strerror(int errnum);
size_t my_strlen(const char *Str);
char *my_strpbrk(const char *StrAddress1, const char *StrAddress2);
char *my_strrchr(const char *Str, int C);
size_t my_strspn(const char *Str1, const char *Str2);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok1(char *str, const char *delim);
char *my_strtok(char *str, const char *delim);
size_t my_strxfrm(char *dest, const char *src, size_t n);

#endif