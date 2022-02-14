/*
 * typequalifiers.c
 *
 *  Created on: 03-Feb-2022
 *      Author: Wafa
 */

#include<stdio.h>
#include<stdint.h>

int main() {
	//1.Normal int variable data
	uint8_t data = 70;
	printf("int variable data value update\n");
	printf("data is %d\n", data);
	data = 80;
	printf("updated data is %d\n", data);

	//2.Const type qualifier.
	uint8_t const data1 = 70;
	printf("const int variable data value update by pointer method\n");
	printf("data1 is %d\n", data1);
	//data1 = 80; --read only variable cannot be altered .
	//printf("data1 is %d\n",data1);
	//Change value for const variable by pointer method
	uint8_t *ptr;
	ptr = (uint8_t*) &data1;
	*ptr = 60;
	printf("updated data1 is %d\n", data1);

	//3.modifiable pointer and constand data
	//address can be varied, but data should be constand
	uint8_t const *ptr1 = (uint8_t*) 0x50000;
	printf("ptr1 address is %p\n", ptr1);
	ptr1 = (uint8_t*) 0x60000;
	printf("ptr1 address is %p\n", ptr1);

	//4.constand pointer and modifiable data
	uint8_t q=7;
	uint8_t *const ptr2 = &q;
	*ptr2 = 50;
	printf("ptr2 value is %u\n", *ptr2);
	*ptr2 = 60;
	printf("ptr2 value is %u\n", *ptr2);

	//5.both pointer and data are constands

	uint8_t const t =89;
	uint8_t const *const ptr3 = &t;
	printf("ptr3 is %d\n", *ptr3);

	return 0;

}

