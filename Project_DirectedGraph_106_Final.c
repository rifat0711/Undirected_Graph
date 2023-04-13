#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
int a[5000][5000];

int main()
{
    int i,j,n,m,in_degree=0,out_degree=0,Total_out=0,Total_in=0;
    printf("Enter the number of rows:");
    scanf("%d",&m);
    printf("Enter the number of column:");
    scanf("%d",&n);
    double start,end,time;



    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            a[i][j]=rand()%2;
           a[i][j]!=a[j][i];
        }
    }


    //printf("Represent the directed graph shown adjacency matrix:\n");

    //for(i=0; i<m; i++)
   //{
       // for(j=0; j<n; j++)
       // {
            //printf("%d ",a[i][j]);
        //}
        //printf("\n");
    //}

    start=clock();
    for(i=0; i<n; i++)
    {
        out_degree=0;
        for(j=0; j<m; j++)
        {
            if(a[i][j]==1)
            {
                out_degree=out_degree+1;
                Total_out++;
            }
        }
        //printf("Out degree of %dth row= %d\n",i+1,out_degree);   //if you can see row wise out_degreee
    }
   printf("Total out degree = %d\n",Total_out);

    for(j=0; j<m; j++)
    {
        in_degree=0;
        for(i=0; i<n; i++)
        {
            if(a[i][j]==1)
            {
                in_degree=in_degree+1;
                Total_in++;
            }
        }
        //printf("In degree of %dth column = %d\n",j+1,in_degree);   //if you can see column wise in_degreee
    }
    printf("Total in degree = %d\n",Total_in);

    if(Total_in == Total_out ) {
        printf("\nHandshaking theorem is working.\n");
    }
    else
     {
        printf("\nHandshaking theorem is not working.\n");
    }

    end=clock();
    time=((end-start)/CLOCKS_PER_SEC)*1000;

    printf("Computational time is : %.4f ms\n", time);

    return 0;

}

