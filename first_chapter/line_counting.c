#include <stdio.h>

int main()
{
    // MAIN

    // int c, nl;
    // nl = 0;
    // while ((c = getchar()) != EOF)
    //     if (c == '\n')
    //         ++nl;
    // printf("%d\n", nl);

    // EXERCISE 1.8 Write a program to count blanks, tabs, and newlines

    // int c, nl;
    // nl = 0;
    // while ((c = getchar()) != EOF)
    //     if ((c == '\n') || (c == '\t') || (c == ' '))
    //         ++nl;

    // printf("%d\n", nl);
    
    // EXERCISE 1.9 Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

    // int c, nl;
    // nl = 0;
    // while ((c = getchar()) != EOF)
    // {
    //     if (c == ' ')
    //         ++nl;
    //     else {
    //         if (nl > 0) {
    //             putchar(' ');
    //             putchar(c);
    //             nl = 0;
    //         }
    //         else
    //             putchar(c);
    //     }

                
    // }

    int c, nl;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t'){ 
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b'){ 
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\'){ 
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(c);
        }

                
    }
    
}
