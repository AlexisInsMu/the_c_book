/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequencvoides, and comments. (This program is hard if you do it in full generality.*/

#include<stdio.h>
#define MAXLINE 4000 /* maximum input line length */
#define MAXUNMATCHED 100

int getline(char line[], int maxline);

void copy(char to[], char from[]);
/* print the longest input line */

int unmaParen[MAXUNMATCHED];
int unmaBrac[MAXUNMATCHED];
int unmaBrace[MAXUNMATCHED];
int openParen = 0;
int openBrack = 0;
int openBrace = 0;


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
			if (max > 0) { /* there was a line */
				printf("%d", max);
				int p;
				for (p = 0; p < MAXUNMATCHED; p++)
				{
					if (openBrace > 0)
					{
						openBrace -= 2;
						printf("In line: %d have a open Brace\n ", unmaBrace[openBrace]);
					}
					if (openBrack > 0)
					{
						openBrack -= 2;
						printf("In line: %d have a open bracker\n ", unmaBrac[openBrack]);
					}
					if (openParen > 0)
					{
						openParen -= 2;
						printf("In line: %d have a open Parentesis\n ", unmaParen[openParen]);
						
					}
					else if (openBrace <= 0 && openParen <= 0 && openBrack <= 0) {
						break;
					}
				}
			}
		}
	return 0;
}

int getline(char s[], int lim)
{
	int c, i, cont, type_commend, conLine;
	cont = 0;
	type_commend = 0;
	conLine = 1;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i) {
		if (c == '\n')
		{
			conLine++;
		}
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
			if (type_commend != 2 && type_commend != 1)
			{
				if (c == '{')
				{
					unmaBrace[openBrace] = conLine;
					openBrace++;
					unmaBrace[openBrace] = '{';
					openBrace++;
				} else if (c == '[')
				{
					unmaBrac[openBrack] = conLine;
					openBrack++;
					unmaBrac[openBrack] = '[';
					openBrack++;
				} else if (c == '(')
				{
					unmaParen[openParen] = conLine;
					openParen++;
					unmaParen[openParen] = '(';
					openParen++;
				} else if (c == '}')
				{
					if (openBrace >= 2)
					{
						if (unmaBrace[openBrace - 1] == '{')
						{
							openBrace--;
							unmaBrace[openBrace] = '\0'; 
							openBrace--;
							unmaBrace[openBrace] = '\0';
						}
					}else
					{
						unmaBrace[openBrace] = conLine;
						openBrace++;
						unmaBrace[openBrace] = '}';
						openBrace++;
					}
				} else if (c == ']')
				{
					if (openBrack >= 2)
					{
						if (unmaBrac[openBrack - 1] == '[')
						{
							openBrack--;
							unmaBrac[openBrack] = '\0';
							openBrack--;
							unmaBrac[openBrack] = '\0';
						}
					}
					else
					{
						unmaBrac[openBrack] = conLine;
						openBrack++;
						unmaBrac[openBrack] = ']';
						openBrack++;
					}
				} else if (c == ')')
				{
					if (openParen >= 2) {
						if (unmaParen[openParen - 1] == '(')
						{
							openParen--;
							unmaParen[openParen] = '\0';
							openParen--;
							unmaParen[openParen] = '\0';
						}
					}
					else
					{
						unmaParen[openParen] = conLine;
						openParen++;
						unmaParen[openParen] = ')';
						openParen++;
					}
				}
			}
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