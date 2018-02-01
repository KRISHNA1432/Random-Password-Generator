# include <time.h>
# include <stdio.h>
# include <stdlib.h>
#include<ctype.h>


int main()
{
    /* Length of the password */
    int N,u=0,l=0,n=0;
    char password[32];
    int i=0;
    int length = 32;

    valid:
    printf("\n\n\t Enter Length Of Password : ");
    scanf("%d",&N);

    if(!(N>=8&&N<=32))
    {
        printf("please Enter in Valid Range [8-32] ... ");
        goto valid;
        exit(0);
    }

    length = N;

    /* Seed number for rand() */
    srand((unsigned int) time(0));

    /* ASCII characters 33 to 126 */

   again:
    while(i<length) {
        password[i]=(rand() %94 + 33);

        if(isupper(password[i]))
        {
            u++;
        }
        if(islower(password[i]))
        {
            l++;
        }
        if(isdigit(password[i]))
        {
            n++;
        }
        i++;

    }

    if(n==0||u==0||l==0)
    {
        again1:

        n=0;
        u=0;
        l=0;
        i=0;
        goto again;
    }

    printf("\n\n\t Generated Password : ");
    for(i=0;i<length;i++)
    {
        printf("%c",password[i]);
    }

    printf("\n");

    return 0;
}

