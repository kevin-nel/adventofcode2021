/* kevin-nel 2021
 * run with:
 * gcc part-2.c; ./a.out < input;
 * where input is in the same directory;
 * ensure that fileLength is the same as the length of the input data file
 */
#include <stdio.h>
int main()
{
    long int curr=0;
    long int prev=0;
    int fileLength = 2000;
    long int data[fileLength];

    int win=3;
    int sumsSize = (sizeof(data) / sizeof(data[0])) - win+1;
    long int sums[sumsSize];

    // read stdin into array
    int i = 0;
    while(scanf("%ld", &data[i])!= EOF){i++;}
    i=0;

    // make windowed sums
    for(int j = 0; j < sumsSize; j++){
        sums[j] = 0;
        for(int k=0; k < win; k++){
            sums[j] += data[j+k];
        }
    }

    //count increases
    int count=0;
    for(int j = 0;j<sumsSize;j++){
        curr = sums[j];
        if ((curr == prev) || (prev == 0)){
            printf("%d: %ld (no change)\n", j, curr);
        }else if (curr > prev){
            printf("%d: %ld (increased)\n", j, curr);
            count ++;
        }else if (curr < prev){
            printf("%d: %ld (decreased)\n", j, curr);
        }
        prev = curr;
    }
    printf("count of increases: %ld\n", count);
    return 0;
}
