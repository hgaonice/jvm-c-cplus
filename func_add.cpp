#include "stdio.h"
#include "stdlib.h"

// -exec disas /r
// Dump of assembler code for function addx(int, int):
//    0x0000555555555253 <+0>:	f3 0f 1e fa	endbr64
//    0x0000555555555257 <+4>:	55	push   rbp
//    0x0000555555555258 <+5>:	48 89 e5	mov    rbp,rsp
//    0x000055555555525b <+8>:	89 7d fc	mov    DWORD PTR [rbp-0x4],edi
//    0x000055555555525e <+11>:	89 75 f8	mov    DWORD PTR [rbp-0x8],esi
// => 0x0000555555555261 <+14>:	8b 55 fc	mov    edx,DWORD PTR [rbp-0x4]
//    0x0000555555555264 <+17>:	8b 45 f8	mov    eax,DWORD PTR [rbp-0x8]
//    0x0000555555555267 <+20>:	01 d0	add    eax,edx
//    0x0000555555555269 <+22>:	5d	pop    rbp
//    0x000055555555526a <+23>:	c3	ret
// End of assembler dump.



// -exec disas /r
// Dump of assembler code for function addx(int, int):
//    0x0000555555555253 <+0>:	f3 0f 1e fa	endbr64 
//    0x0000555555555257 <+4>:	55	push   rbp
//    0x0000555555555258 <+5>:	48 89 e5	mov    rbp,rsp
//    0x000055555555525b <+8>:	89 7d fc	mov    DWORD PTR [rbp-0x4],edi
//    0x000055555555525e <+11>:	89 75 f8	mov    DWORD PTR [rbp-0x8],esi
// => 0x0000555555555261 <+14>:	8b 55 fc	mov    edx,DWORD PTR [rbp-0x4]
//    0x0000555555555264 <+17>:	8b 45 f8	mov    eax,DWORD PTR [rbp-0x8]
//    0x0000555555555267 <+20>:	01 d0	add    eax,edx
//    0x0000555555555269 <+22>:	5d	pop    rbp
//    0x000055555555526a <+23>:	c3	ret    
// End of assembler dump.

// const unsigned char codes[] = {0x55, 0x48, 0x89, 0xe5, 0x89, 0x7d, 0xfc, 0x89, 0x75, 0xf8, 0x8b, 0x55, 0xfc, 0x8b, 0x45, 0xf8, 0x01, 0xd0, 0x5d, 0xc3};
const unsigned char codes[] = {0xf3 , 0x0f , 0x1e , 0xfa, 0x55, 0x48, 0x89, 0xe5, 0x89, 0x7d, 0xfc, 0x89, 0x75, 0xf8, 0x8b, 0x55, 0xfc, 0x8b, 0x45, 0xf8, 0x01, 0xd0, 0x5d, 0xc3};
// const unsigned char codes[] = {0x55, 0x48, 0x89, 0xe5, 0x89, 0x4d, 0x10, 0x89, 0x55, 0x18, 0x8b, 0x55, 0x10, 0x8b, 0x45, 0x18, 0x01, 0xd0, 0x5d, 0xc3};

int main()
{
    int x = 2, y = 5;

    int (*func_ptr)(int x, int y);
    func_ptr = (int (*)(int, int))codes;

    printf("addy ===>%p\n", func_ptr);

    printf("====>%d\n", func_ptr(x, y));

    return 0;
}