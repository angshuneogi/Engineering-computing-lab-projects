//C program to perform Gauss elimination and solve a set of linear equations//
#include<stdio.h>
#include<stdlib.h>

int main()
{

int i,j,k,n=0,p=1; //declaration of variables
char ch;
float c,x[i],sum=0.0;

FILE *fp1;

fp1=fopen("data1.txt","r");        //opening of text file
if(fp1==NULL)
    printf("\nSource file could not be found\n");    //error message if no such file with that name exists
else
{
    while((ch=fgetc(fp1))!=EOF)
{
	if(ch=='\t'&&n==0)   //reading from text file with data separated with tab and newline
	p++;
	else if(ch=='\n')
	n++;
}
printf("Number of rows and columns of the augmented matrix in the file are : %d and %d respectively\n\n",n,p);
fclose(fp1);

float m[n][p];

printf("The augmented matrix from the file 'data1.txt' is :\n\n");
fp1=fopen("data1.txt","r");

while(!feof(fp1))
{
	for(i=1;i<=n;i++)
		for(j=1;j<=p;j++)
		fscanf(fp1,"%f",&m[i][j]);
}

for(i=1;i<=n;i++)
	{
		for(j=1;j<=p;j++)
		{
			printf("%.4f\t",m[i][j]);     //printing augmented matrix
		}
	printf("\n");
	}
if(p!=n+1)
    printf("\nThe system of linear equations can not be solved\n");  //error message if the original matrix
                                                                     //containing coefficients of variables
                                                                    //is not a square matrix
else
{
    for(i=1;i<=n;i++)    //loop for elimination process
	{
	    if(m[i][i]==0.0)
        {
            printf("\nCan not be solved by Gauss Elimination method!\n");    //error message as denominator can't be zero
            return 0;
        }
		for(j=1;j<=n;j++)
		{
		    if(j>i)
            {
                c=m[j][i]/m[i][i];
                for(k=1;k<=n+1;k++)
            {
                m[j][k]=m[j][k]-c*m[i][k];
            }
            }

		}

	}
	printf("The upper triangular matrix is :\n");

        x[n]=m[n][n+1]/m[n][n];

	for(i=n-1;i>=1;i--)    //loop to find solutions
    {
        sum=0.0;
        for(j=i+1;j<=n;j++)
        {
            sum=sum+m[i][j]*x[j];
        }
        x[i]=(m[i][n+1]-sum)/m[i][i];
    }
    printf("\nThe solutions of the given linear system of equations are: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx[%d]=%.4f\n",i,x[i]); //x[1],x[2],.... are the solutions of given linear equations
    }
  }
 }
 return 0;
}
