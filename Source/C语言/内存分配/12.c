#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
		   char *str;

		      /* 最初的内存分配 */
		      str = (char *) malloc(15);
			     strcpy(str, "runoob");
				    printf("String = %s,  Address = %u\n", str, str);

					   /* 重新分配内存 */
					   str = (char *) realloc(str, 25);
					      strcat(str, ".com");
						     printf("String = %s,  Address = %u\n", str, str);

							    free(str);
								   
								   return(0);
}


/*
 *
 *
  String = runoob,  Address = 150843400
  String = runoob.com,  Address = 150844456

 *
 * /
