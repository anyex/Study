#include <stdio.h>  
int main(int argc, char* argv[])  
{  
    char* abc = "abc";  
    printf("%s\n", abc);  
    char* abd = 0;  
    char coredump = abd[0];  
    printf("%c\n", coredump);  
    return 0;  
}  

