/*
 * main.c
 *
 *  Created on: 01-Mar-2022
 *      Author: Wafa
 */

#include<stdio.h>
#include "list.h"
extern list* createlist(char[]);
extern list* createlistwithoutrecursion(char[]);
extern void traverselist(list*);
extern int searchlist(list*, char);
extern list* insertelist(list*, char);
extern list* deletelist(list*, char);
extern list* concatenatelist(list *, list *);

int main() {
	char n[50];
	list *h,*a,*b;
	int l;
	printf("Input string\n");
	scanf("%s", &n);
	//h = createlist(n); //create list with recursion
	h = createlistwithoutrecursion(n); //create list without recursion
	printf("list created\n");
	traverselist(h); //print list elements
	printf("list traversed\n");
	l = searchlist(h, 'f');
	if (l == 1)
		printf("letter f found in search\n");
	else
		printf("letter f not found in search\n");
	h = insertelist(h, 'd');
	printf("value inserted\n");
	traverselist(h); //print list elements
	printf("element inserted list printed\n");
	h = deletelist(h, 'G'); //delete letter G
	traverselist(h); //print list elements
	printf("element deleted list printed\n");
	a=h;
	b=createlistwithoutrecursion("Morning");
	h=concatenatelist(a,b);
	traverselist(h);
	printf("lists concatenated");

	return 0;
}

