/*** 
 * @Author: gaoh
 * @Date: 2024-08-26 23:15:29
 * @LastEditTime: 2024-08-26 23:19:49
 */
#include "swap.h"
void swap(int& a,int& b){
    int  temp =a;
    a = b;
    b = temp;
}