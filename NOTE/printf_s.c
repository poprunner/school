#include <stdio.h>
char* value = "Hello world!";
char value2[] = {"Hello world!"};
char* formatStr = "%s%d\n";
int main()
{
    printf(formatStr, value,10);   // 可以輸出"Hello world!10"
    printf_s(formatStr, value, 10);// 會報錯   
    return 0;
}
