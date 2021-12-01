/* kevin-nel 2021
 * run with:
 * gcc part-1.c; ./a.out < input;
 * where input is in the same directory;
 */
#include <stdio.h>
int main()
{
    int curr=0;
    int prev=0;
    int count=0;
    while(scanf("%d", &curr)!= EOF)
    {
        if ((curr == prev) || (prev == 0)){
            printf("%d (no change)\n", curr);
        }else if (curr > prev){
            printf("%d (increased)\n", curr);
            count += 1;
        }else if (curr < prev){
            printf("%d (decreased)\n", curr);
        }        prev = curr;
    }
    printf("count of increases: %d\n", count);
    return 0;
}
