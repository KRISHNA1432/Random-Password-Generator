# include <time.h>
# include <stdio.h>
# include <stdlib.h>


int main()
{
    /* Length of the password */
    int N,capital=0,small=0,number=0,special=0,i=0,SIZE=32;
    char password[32];


    do
    {

    printf("\n\n\t Enter Length Of Password : ");
    scanf("%d",&N);

    if(N<8)      /*CHECKING VALID RANGE */
        printf("RANGE TOO SMALL\n\nplease Enter in Valid Range [8-32] ... ");

        if(N>32)
        {
            printf("RANGE TOO LARGE\n\nplease Enter in Valid Range [8-32] ... ");
        }

    }while(!(N>=8&&N<=32));

    SIZE = N;

    /* THIS FUNCTION IS USED TO LOOK OUT NUMBER FOR RAND() */

    srand((unsigned int) time(0));

   REPEAT:

    while(i<SIZE)
        {
            password[i]=(rand() %94 + 33);  /*THIS WILL GET ASCII CHARACTER FOR 33 TO 126 */

            if(password[i]>='A'&&password[i]<='Z')
            {
                capital++;
            }
            if(password[i]>='a'&&password[i]<='z')
            {
                small++;
            }
            if(password[i]>='0'&&password[i]<='9')
            {
                number++;
            }

            if((password[i]>=33&&password[i]<=47)||
               (password[i]>=58&&password[i]<=64)||
                (password[i]>=91&&password[i]<=96)||
                (password[i]>=123&&password[i]<=126))
            {
                special++;
            }
            i++;
        }

    if(number==0||capital==0||small==0||special==0)
    {
        number=0;
        capital=0;
        small=0;
        special=0;
        i=0;

        goto REPEAT;
    }

    printf("\n\n\t HELLO FELLA !!! \n\n\t\t\t YOUR PASSWORD : ");

    for(i=0;i<SIZE;i++)
    {
        printf("%c",password[i]);
    }

    printf("\n");

    return 0;
}

