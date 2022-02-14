/*
 * Bit.c
 *
 *  Created on: 14-Feb-2022
 *      Author: Wafa
 */

#include<stdio.h>

int main() {
	int input1, input2;
	int or_result = 0, and_result = 0, xor_result = 0, not_result = 0,
			rightsh_result = 0, leftsh_result = 0;
	printf("Enter user inputs, input1 and input2");
	scanf("%d, %d", &input1, &input2);
	or_result = input1 | input2;
	printf("OR value of input1 %d and input2 %d is %d\n", input1, input2,
			or_result);
	and_result = input1 & input2;
	printf("AND value of input1 %d and input2 %d is %d\n", input1, input2,
			and_result);
	xor_result = input1 ^ input2;
	printf("XOR value of input1 %d and input2 %d is %d\n", input1, input2,
			xor_result);
	not_result = ~input1;
	printf("NOT value of input1 %d is %d\n", input1, not_result);
	not_result = ~input2;
	printf("NOT value of input2 %d is %d\n", input2, not_result);
	leftsh_result = (1 << input2);
	printf("left shift value of 1 shifted by input2 bits/%d is %d\n", input2,
			leftsh_result);
	leftsh_result = (1 << input1);
	printf("left shift value of 1 shifted by input1 bits/%d is %d\n", input1,
			leftsh_result);
	rightsh_result = (1 >> input1);
	printf("right shift value of 1 shifted by input1 bits/%d is %d\n", input1,
			rightsh_result);
	rightsh_result = (1 >> input2);
	printf("right shift value of 1 shifted by input2 bits/%d is %d\n", input2,
			rightsh_result);

}

