#include<stdio.h>
int main()
{
    int i,j,n;
    double cp[20],supplyT[20],targetT[20],supplyST[20],targetST[20],sortedStream[40],dH[20],dTmin=10.0;

    printf("Enter the total number of streams:\n");
    scanf("%d",&n);
    printf("------------------------------------------------------------------\n");

    printf(" CP     | Ts    | Tt    |\n");

    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf",&cp[i],&supplyT[i],&targetT[i]);


        if(targetT[i]<supplyT[i])
        {
           supplyST[i]=supplyT[i]-dTmin/2;
           targetST[i]=targetT[i]-dTmin/2;
        }
        else
        {
           supplyST[i]=supplyT[i]+dTmin/2;
           targetST[i]=targetT[i]+dTmin/2;
        }

        printf("%lf   |%lf    |\n",supplyST[i],targetST[i]);

        printf("-----------------------------\n");
    }

    for(i=0;i<2*n;i++)
    {
        if(i<n)
        sortedStream[i]=supplyST[i];
        else
        sortedStream[i]=targetST[i-n];

        //printf("%lf \n",sortedStream[i]);

    }

    for(i=0;i<2*n;i++)
    {
        if(sortedStream[i]==sortedStream[i+1])
        {
            for(j=i;j<2*n;j++)
            {
            sortedStream[j]=sortedStream[j+1];
            }
        }
        printf("%lf \n",sortedStream[i]);
    }

}
