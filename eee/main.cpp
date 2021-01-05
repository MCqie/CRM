#include <stdio.h>
int main( )
{
    int i,n=0;
    for(i=2;i<5;i++)
    {
        do
        {
            if(i%3) continue;
            n++;
        }while(!i);
        n++;
    }
    printf("n=%d\n",n);
    return 0;
}