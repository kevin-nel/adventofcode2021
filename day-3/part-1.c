/* kevin-nel 2021
 * advent of code day 3 part 1
 * run with:
 * gcc -pedantic -Wall -Wextra part-1.c; ./a.out < input 
 * where input is in the same directory;
 * i used the char arrays because i couldn't figure out how to use binary numbers
 * i didn't want to use any other libraries so i implemented the binary to decimal and power functionality.
 */
#include <stdio.h>
int main()
{
    int bitDepth = 12; // length of binary numbers
    const int fileLength = 1000; //length of input file
    char data[fileLength][bitDepth + 1];
    int countZeroes;
    int countOnes;
    char gamma[bitDepth];
    char epsilon[bitDepth];
    int decGamma;
    int decEpsilon;
    int base=1;
    int power;

    // read stdin to array
    for(int i=0; i<fileLength; i++){
        scanf("%12s", data[i]); // use bit depth
    }

    for(int j=0;j<fileLength;j++){printf("%s\n",data[j]);}

    //cols
    for(int j=0; j<bitDepth; j++){
        //rows
        for(int i=0; i<fileLength; i++){
            if (data[i][j]=='1'){countOnes++;}
            else if (data[i][j]=='0'){countZeroes++;}
            else {printf("error at i:%d and j:%d\n",i,j);}
        }
        if (countZeroes > countOnes){
            gamma[j] = '0';
            epsilon[j] = '1'; // use ones complement on gamma if you had binary capability
        }
        else if (countZeroes < countOnes){
            gamma[j] = '1';
            epsilon[j] = '0';
        }
        countZeroes =0;
        countOnes =0;
    }
    printf("gamma: %s\n",gamma);
    printf("epsilon: %s\n",epsilon);

    //bin to dec
    for(int i=0, j=bitDepth; i<bitDepth && j>0; i++,j--){
        base = 1;
        for(int k=0; k<j-1; k++){
            base*=2;
        }
        decGamma += ((int)gamma[i] - 48 )*base; // convert ascii numbers to integers 0 integer is 48 in ascii
        decEpsilon += ((int)epsilon[i] - 48 )*base;
    }

    printf("gamma: %d\n", decGamma);
    printf("epsilon: %d\n", decEpsilon);
    power = decGamma * decEpsilon;
    printf("power: %d\n", power);
    return 0;
}
