/*
 * exist_reg.c
 *
 *  Created on: 26-Jan-2022
 *      Author: Wafa
 */

#include "regist.h"

//Hardcoded 3 members data for testing purpose.

int exist_reg() {

	//Patient 1
	pd[0].age = 23;
	pd[0].adhar = 123456;
	pd[0].phonenumber = 12345678;
	pd[0].secretcode = 9786;
	pd[0].vaccinetype = 1;
	pd[0].vaccinedoses = 1;

	//patient 2

	pd[1].age = 32;
	pd[1].adhar = 654321;
	pd[1].phonenumber = 87654321;
	pd[1].secretcode = 6879;
	pd[1].vaccinetype = 2;
	pd[1].vaccinedoses = 0;

	//patient 3
	pd[2].age = 50;
	pd[2].adhar = 456321;
	pd[2].phonenumber = 56784321;
	pd[2].secretcode = 8769;
	pd[2].vaccinetype = 1;
	pd[2].vaccinedoses = 2;

	return 0;
}

