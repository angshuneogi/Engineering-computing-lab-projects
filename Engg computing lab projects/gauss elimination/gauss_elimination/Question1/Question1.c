#include<stdio.h>
#include<stdlib.h>


int main()
{ // The two input values
int i,j,k,r1=0,c1=1,r2=0,c2=1;
char ch;


FILE *fp1;
//FILE *fp2;
 //FILE *outputFile1;

fp1=fopen("data1.txt","r");


while((ch=fgetc(fp1))!=EOF)
{
	if(ch=='\t'&&r1==0)
	c1++;
	else if(ch=='\n')
	r1++;
}

printf("Number of rows and columns of the 1st matrix are : %d and %d respectively\n\n",r1,c1);
fclose(fp1);

float m1[r1][c1];

printf("The matrix from the file 'data1.txt' is :\n\n");
fp1=fopen("data1.txt","r");
while(!feof(fp1))
{
	for(i=0;i<r1;i++)

		for(j=0;j<c1;j++)
		fscanf(fp1,"%f",&m1[i][j]);

}

for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%.4f\t",m1[i][j]);
		}
	printf("\n");
	}


FILE *fp2;

fp2=fopen("data2.txt","r");


while((ch=fgetc(fp2))!=EOF)
{
	if(ch=='\t'&&r2==0)
	c2++;
	else if(ch=='\n')
	r2++;
}

printf("\nNumber of rows and columns of the 2nd matrix are : %d and %d respectively\n\n",r2,c2);
fclose(fp2);
float m2[r2][c2];

printf("The matrix from the file 'data2.txt' is :\n\n");
fp2=fopen("data2.txt","r");
while(!feof(fp2))
{
	for(i=0;i<r2;i++)

		for(j=0;j<c2;j++)
		fscanf(fp2,"%f",&m2[i][j]);

}
for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%.4f\t",m2[i][j]);
		}
	printf("\n");
	}



 if(c1!=r2)
 {
 printf("Matrix multiplication is not possible as number of columns of 1st matrix and number of rows of 2nd matrix differ\n");
 fclose(fp1);
 fclose(fp2);
 return 0;
 }

 else
 {

//multiplication statements
float m3[r1][c2];

 for(i=0;i<r1;i++)
 {
  for(j=0;j<c2;j++)
  {
 m3[i][j]=0;
  }
 }
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c2;j++)
  {
  for(k=0;k<r2;k++)
    m3[i][j]+=m1[i][k]*m2[k][j];
  }

 }

 //print multiplication result
 printf("\n\nThe resultant matrix from matrix multiplication is : \n\n");

 for(i=0;i<r1;i++)
 {
 for(j=0;j<c2;j++)
  {printf("%0.4f\t",m3[i][j]);
  }
 printf("\n");
 }


FILE *fp3;
fp3=fopen("data3.txt","w");
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
fprintf(fp3,"%0.4f\t",m3[i][j]);
}
fprintf(fp3,"\n");
}
fclose(fp3);
printf("\nThe result of matrix and vector multiplication is written in a file named 'data3.txt' \n");
// close the input files
 fclose(fp1);
 fclose(fp2);
 }
 }
