/*
 * regist.h
 *
 *  Created on: 26-Jan-2022
 *      Author: Wafa
 */

#ifndef REGIST_H_
#define REGIST_H_

//Structure definition for personal vaccine registraion
typedef struct patient{
	int age;
	long adhar;
	long phonenumber;
	int secretcode;
	int vaccinetype;
	int vaccinedoses;
}pat;
//per day 1000 members can register.
pat pd[1000];

#endif /* REGIST_H_ */
