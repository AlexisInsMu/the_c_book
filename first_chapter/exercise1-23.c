/*Exercise 1 - 23. Write a program to remove all comments from a C program.Don't forget to
handle quoted strings and character constants properly.C comments don't nest.*/

#include<stdio.h>
#define MAXLINE 3000 /* maximum input line length */

int getline(char line[], int maxline);

void copy(char to[], char from[]);
/* print the longest input line */

int main() {

	int len;               /* current line length */
	int max;               /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
			if (len >= 10) {
				printf("\n%s", longest);
			}
		}
	if (max > 0) { /* there was a line */
		printf("%d", max);
	}
	return 0;
}

int getline(char s[], int lim)
{
	int c, i, cont, type_commend;
	cont = 0;
	type_commend = 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i) {
		if ((c == '/' || cont == 1) && (type_commend != 1 && type_commend != 2)) // evalua inicio de comentario
		{
			if (c == '/' && cont == 1) {
				type_commend = 1;
				cont = 0;
				i -= 2;
			} // evalua si el comentario es de una linea type_comment = 1
			else if (c == '*' && cont == 1) {
				type_commend = 2;
				cont = 0;
				i -= 2;
			}// evalua si el comentario es de multilinea type_comment = 2
			else if (cont == 0) {
				cont = 1;
			}
			else
			{
				cont = 0;
				s[i - 1] = '/';
				s[i] = c;
			}
		}
		else if (type_commend == 1)
		{
			if (c == '\n') {
				type_commend = 0;
				--i;
				cont = 0;
			}
			else
			{
				i--;
			}
		}
		else if (type_commend == 2)
		{
			if (c == '*') {
				cont = 2;
			}
			else if (c == '/' && cont == 2)
			{
				type_commend = 0;
				i -= 2;
				cont = 0;
			}
			else if (c != '/' && cont == 2)
			{
				s[i - 1] = '*';
				s[i] = c;
				cont = 0;
			}
			else
			{
				i--;
			}
		}
		else {
			s[i] = c;
		}
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;

}