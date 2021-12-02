/* kevin-nel 2021
 * advent of code day 2 part 2
 * run with:
 * gcc part-2.c; ./a.out < input;
 * where input is in the same directory;
 */
#include <stdio.h>
int main()
{
    int datum;
    char command[10];
    int pos=0;
    int depth=0;
    int aim=0;

    // read stdin
    int i = 0;
    // this only reads the last character of the word
    while(scanf("%s %d", &command, &datum)!= EOF){
        printf("%s:%d\n",command,datum);
        i++;
        if(command[0]=='f'){
            pos+=datum;
            depth+=aim*datum;
        }else if(command[0]=='d'){
            aim+=datum;
        }else if(command[0]=='u'){
            aim-=datum;
        }
    }

    printf("\ndepth: %d\n",depth);
    printf("pos: %d\n",pos);
    printf("aim: %d\n",aim);
    printf("answer: %d\n",pos*depth);

    return 0;
}
