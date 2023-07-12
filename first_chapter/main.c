#include <stdio.h>

int main(){
    int c,f;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
        f = (c != EOF);
        printf("\n %d", f);
        printf("\n %d", EOF);
    }
    
}
