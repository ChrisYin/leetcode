
#include <stdio.h>


int main(){
    int c;

    while((c = getchar()) != EOF){
        putchar(c);
    }
    printf("%u\n", EOF);
    return 0;
}