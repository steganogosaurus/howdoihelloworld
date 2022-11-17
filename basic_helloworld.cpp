#include <stdio.h>
#include <string.h>

void printmsg(char *msg, int len){
    asm(    "movl $4, %eax;"
            "movl $1, %ebx;"
       );
    asm(    "movl %1, %%ecx;"
            "movl %1, %%edx;"
            :
            : "c" (msg), "d" (len)
        );
    asm("int $0x80");
}

int main(){
    char *msg = "Hello World!";
    int len = strlen(msg);

    printf("%s\n",msg);

    /* Print msg */
    printmsg(msg, len);

    /* Exit */
    asm(    "movl $1,%eax;"
            "xorl %ebx,%ebx;"
            "int  $0x80"
    );
}
