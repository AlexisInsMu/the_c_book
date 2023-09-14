//
// Author: Murillo Alexis
//
//Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
//of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
//Should n be a variable or a symbolic parameter? 
/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.*/

#include <stdio.h>


void detab( void ); 
void entab (int con);
void foldLine ( int a,int contador);

int main () {
	int c;
	int count = 0;
	int count2 = 0;
	while ((c = getchar()) != EOF)
	{
		if (count2 > 40){
			foldLine(c, count2);
			count = count2 = 0;
		}
		else if (c == ' ')
			count++;
		else if (count > 0 && c != ' ') {
			entab (count);
			count = 0;
			putchar(c);
		}
		else if (c == '\t')
			detab();
		else
			putchar(c);
		count2++;
	}
	return 0;
}

void detab (void) {
	printf("    ");
}

void entab (int insi) {
	int i = 0;
	while (1)
	{
		if ((insi - i) >= 4){
			i += 4;
			detab();
		}else if((insi - i) < 1)
			break;
		else if ((insi - i) < 4){
			printf("s");
			i++;
		}
	}
}

void foldLine(int ch, int cont)
{
	if (cont > 40 && (ch == ' ' || ch == '\t')){
			putchar('\n');
			putchar(ch);
	} else if (cont > 40 && (ch != ' ' || ch != '\t')) {
			printf("- \n");
			putchar(ch);
	}
}

