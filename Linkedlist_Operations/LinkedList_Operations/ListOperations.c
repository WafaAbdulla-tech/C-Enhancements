/*
 * ListOperations.c
 *
 *  Created on: 01-Mar-2022
 *      Author: Wafa
 */

#include "list.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//add element
//list creation with recursion
list* createlist(char s[]) {

	list *head;
	if (s[0] == '\0')

		return NULL;

	else {
		head = malloc(sizeof(list));
		head->d = s[0];
		//printf("Element added %c\n", head->d);
		head->next = createlist(s + 1);
		//printf("value added ----%c--------------\n", head->d);
		return head;
	}

}

//list creation without recursion

list* createlistwithoutrecursion(char s[]) {
	int i;
	list *head, *tail;
	if (s[0] != '\0') {
		head = malloc(sizeof(list));
		head->d = s[0];
		//printf("val is %c\n", head->d);
		tail = head;
		for (i = 1; s[i] != '\0'; i++) {

			tail->next = malloc(sizeof(list));
			tail = tail->next;
			tail->d = s[i];
			//printf("val is %c\n", tail->d);
		}
		tail->next = NULL;

		return head;
	} else
		return NULL;

}

//Traverse list

void traverselist(list *head) {

	if (head == NULL) {
		printf("list is NULL or reached lastnode\n");
	} else {
		printf("%c\n", head->d);
		head = head->next;
		traverselist(head);
	}

}

//Search an element in list
int searchlist(list *head, char e) {
	int i = 0;
	while (head != NULL) {
		if (e == head->d) {
			i = 1;
			break;
		}
		head = head->next;

	}

	return i;
}

//Insert an element in to list

list* insertelist(list *head, char e) {
	list *tail;
	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = malloc(sizeof(list));
	tail = tail->next;
	tail->d = e;
	tail->next = NULL;
	return head;

}

//Delete an element from list

list* deletelist(list *head, char e) {
	list *tail, *pretail;
	tail = head;
	while (tail->d != e && tail->next != NULL) {
		pretail = tail;
		tail = tail->next;
	};

	if (tail->d == e) {
		if (tail == head) {
			{
				head = tail->next;
			}

		} else if (tail->next == NULL) {

			pretail->next = NULL;
		} else
			pretail->next = tail->next;
		printf("first %c deleted from list \n", e);

	} else if (tail->next == NULL)
		printf("element not present in list\n");

	return head;
}
//Concatenate lists

list* concatenatelist(list *a, list *b) {
	list *head = a;
	if (a == NULL && b == NULL) {
		printf("list is empty");
		head = NULL;
	} else if (a == NULL && b != NULL)
		head = b;
	else {
		while (a->next != NULL)
			a = a->next;
		a->next = b;
	}

	return head;

}

