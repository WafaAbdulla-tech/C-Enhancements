//calculates elephant seal average ( seal values from  elephant_seal_data file stores in to an array and calculates its average.)
#include<stdio.h> // Used for printf(), FILE structure, fgets()
#include<stdlib.h> //Used for atoi() string to integer conversion.

int main()
{
    //Created 2 file pointers one for collecting total number of elements in file, and 2nd for storing file values in to an array.
    FILE *fp, *farray;
    //fp is a file structure pointer which opens elephant seal data file in read mode 
    fp = fopen("elephant_seal_data", "r");
    char ch[6]; //ch is of 10 character string
    long int i = 0, j, temp1;
    double sum = 0.0, avg;
    //below while loop checks number of values in file and stores the total number of values in  variable i
    while(fgets(ch,7,fp)!=NULL)//checks for string of character 7 size (4 digits, 2 spaces and \0 --- total 7)and increments the file pointer untill EOF
    {
        printf("%s\n", ch);
        i++;
    }
    printf("i is %ld\n", i);
    fclose(fp);//closes file
    long int a[i];//defines array with i number of elements
    farray = fopen("elephant_seal_data", "r");//opening file again in read mode for to store file values in array.
    while ((fgets(ch, 7, farray) != NULL) && (j<i))
    {
        temp1 = (long int)atoi(ch); //converts string to int and then cast to long int since string is of 8 byte.
        a[j] = temp1; //long int value stores in to array
        sum = sum + a[j]; //calculating total seal sum
        printf("a[%ld] is %ld\n", j, a[j]);
        j++; //increments array index
    }
    printf("sum is %lf\n", sum);
    avg = sum / i; //calculates average.
    printf("elephant seal average is %lf\n", avg);
    fclose(farray); //closes file
    return 0;
}