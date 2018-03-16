#include "stdio.h"
#include "string.h"
int main()
{
   char str[100],st[100];
   scanf("%[a-z]%[^a-z]",str,st);//只要小写字符，不要小写字母
   puts(str);
   puts(st);
   return 0;

}
/*对于scanf()语句：
 *
 *"%s" 整个输入作为一个串,并设置末尾的'\0'
 "%ns",n为整数,读入的串最长不超过n,然后在末尾补'\0'
 %nf 读入的浮点数最多有n位整数,位数多于n,会截断。
 "%n[a-z]" 读入最多n个字符,如果遇到非a-z的字符,停止
 "%[^=]" 读入任意多的字符,直到遇到"="停止
 "%n[^=]" 读入"="号前的至多n 个字符
 *
 * */
