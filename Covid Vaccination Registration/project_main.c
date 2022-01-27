/*
 * project_main.c
 *
 *  Created on: 26-Jan-2022
 *      Author: Wafa
 */

#include "regist.h"
#include <stdio.h>
#include <errno.h>

#define COVISHIELD 1
#define COVAXIN 2

//Invoking external functions
extern int exist_reg();
extern int new_register(long);
extern void vaccine_status(long);

int main() {
	exist_reg(); //Invoking existing data elements
	long aad, phone;
	int secretcde,check, count = 0;
	char h, y = 'n';
	printf("--------------------------------------------\n");
	printf("Welcome to COVID 19 Vaccination Registration Portal\n");
	printf("----------------------------------------------\n");
	printf(
			"do you want to change the vaccine,which you prevoiusly selected; Valid only for Unvaccinated people. if yes input y or no input n \n");
	scanf("%c", &h);
	printf("Enter Aadhar Number\n");
	scanf("%ld", &aad);

	//Variable check stores the upcoming vaccination to be taken by the user.
	//check =1 :Take first dose
	//check =2:Take second dose.
	//check =3:Two doses taken, Vaccination completed.
	check = new_register(aad); //New register function prompts user to register if new, else continue to login
	while (count < 1000) {
		if (pd[count].adhar == aad) {
			break;
		}
		count++;

	}

	system("cls");
	if ((check == 1 || check == 2 || check == 3) && pd[count].adhar == aad) {

		try: printf("enter your phone number\n");
		scanf("%ld", &phone);
		if (pd[count].phonenumber == phone) {
			printf("Mobile number correct, User validated successfully!\n");
		} else {
			printf("wrong phone number entered\n");
			goto try;
		}

		validatesecretcode:printf("enter your secret code\n");
		scanf("%d", &secretcde);
		if (pd[count].secretcode == secretcde) {
			printf("Secret code correct,User validated successfully!\n");
		} else {
			printf("wrong secret code entered\n");
			goto validatesecretcode;
		}

		vaccine_status(aad);
		if (check == 1) {

			printf("Note COVISHIED:1, COVAXIN:2\n");
			printf(
					"you  are selected to change/recheck  your first dose of  vaccine, your prevoius selection was %d,\n",
					pd[count].vaccinetype);
			y = h;
			if (y == 'y') {
				printf("Enter new Vaccination type COVISHIED:1, COVAXIN:2\n");
				scanf("%d", &pd[count].vaccinetype);
			}
		}
		char cov[15] = "COVISHIELD";
		char covax[15] = "COVAXIN";
		if (pd[count].vaccinetype == 1) {
			printf("Your vaccine is %s\n", cov);
		} else if (pd[count].vaccinetype == 2) {
			printf("Your vaccine is %s\n", covax);
		}

	}

	return 0;
}
