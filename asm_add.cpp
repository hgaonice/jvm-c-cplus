#include "stdio.h"
/**
 *
 * 汇编完成两个数相加  
 *
 */
int main()
{

    int a = 5;  //%1
    int b = 10; //%2
    int result; //%0

    asm(
        "mov %1,%%eax;"  // 将a加载到寄存器eax中
        "add %2,%%eax;"  // 将b加到eax中
        "mov %%eax,%0;"  // 将eax中的值放入到result中
        : "=r"(result)   // 输出操作数
        : "r"(a), "r"(b) // 输出操作数
        : "%eax"         // 受影响的寄存器
    );
    printf("a:%d,b:%d,result:%d\n", a, b, result);
    return 0;
}