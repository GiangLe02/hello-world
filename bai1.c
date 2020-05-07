#include <stdio.h>
#include <math.h>
int main()
{
    int n, max, x;
    max=0;
    do{
        printf("nhap vao mot so nguyen duong 5 chu so\n");
        scanf("%d", &n);
    } while (n<=9999 || n>=100000);
    for(float i=4;i>=0;i--)
    {
        x= n/(int)pow(10,i);
        n=n%(int)pow(10,i);
        if(x>max)
        {
            max=x;
        }

    }
printf("chu so lon nhat cua so nguyen duong n la %d",max);


    return 0;
}
