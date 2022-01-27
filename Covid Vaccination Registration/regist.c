/*
 * regist.c
 *
 *  Created on: 26-Jan-2022
 *      Author: Wafa
 */

#include "regist.h"
extern int exist_reg();
#include<stdio.h>
#define FirstDose 1
#define SecondDose 2
#define COVISHIELD 1
#define COVAXIN 2

//Registration for New patient, validate with adhar number
int new_register(long aadhar) {
	exist_reg();
	int i = 0;
	while (pd[i].adhar != aadhar && i < 1000 && pd[i].adhar != 0) {
		i++;
	}
	if (pd[i].adhar == aadhar && pd[i].vaccinedoses == 0 && i < 1000) {
		pd[i].vaccinedoses = 1;
		return 1;
	} else if (pd[i].adhar == aadhar && pd[i].vaccinedoses == FirstDose
			&& i < 1000) {
		pd[i].vaccinedoses = 2;
		return 2;

	} else if (pd[i].adhar == aadhar && pd[i].vaccinedoses == SecondDose
			&& i < 1000) {
		return 3;
	}
	if (i < 1000 && pd[i].adhar == 0) {
		printf("New Register\n,enter your age\n");
		scanf("%d", &pd[i].age);
		printf("enter your phone number\n");
		scanf("%ld", &pd[i].phonenumber);
		printf("enter your secretcode\n");
		scanf("%d", &pd[i].secretcode);
		printf(
				"enter your vaccine type , Please give 1 0r 2 : 1-COVISHIELD, 2-COVAXIN \n");
		scanf("%d", &pd[i].vaccinetype);
		pd[i].adhar = aadhar; //Aadhar number given in input
		pd[i].vaccinedoses = 0; //not vaccinated(scheduled 1st dose).
		return 1;
	} else if (i >= 1000 && pd[i].adhar != aadhar) {
		printf(
				"Daily customer limit exceeded Please register on next working day");
		return 0;
	}
	return -1;
}

int new_register(long);
//Check Vaccination status

void vaccine_status(long adhar) {
	int status;
	status = new_register(adhar);
	if (status == 1) {
		printf("Please take your first dose of vaccination\n");
	} else if (status == 2) {
		printf(
				"You are vaccinated first dose, Please take your second dose of vaccination\n");
	} else if (status == 3) {
		printf(
				"You are vaccinated 2 doses/Congratulations you are fully vaccinated\n");
	} else if (status == 0) {
		printf("Please register in portal\n");
	}

}

