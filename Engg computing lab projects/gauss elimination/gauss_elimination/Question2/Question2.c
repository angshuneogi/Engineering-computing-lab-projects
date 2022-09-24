//C program to interchange the rows of a given matrix//
#include<stdio.h>
#include<stdlib.h>

int main()
{

int i,j,r1=0,c1=1,a,b; //declaration of variables
char ch;
float temp;

FILE *fp1;

fp1=fopen("data1.txt","r");        //opening of text file
if(fp1==NULL)
    printf("\nSource file could not be found\n");
else
{
    while((ch=fgetc(fp1))!=EOF)
{
	if(ch=='\t'&&r1==0)
	c1++;
	else if(ch=='\n')
	r1++;
}
printf("Number of rows and columns of the matrix in the file are : %d and %d respectively\n\n",r1,c1);
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
//copying the matrix
float m2[i][j];
for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{m2[i][j]=m1[i][j];}
	}
printf("\nEnter the row numbers of the two rows to be exchanged\n");
scanf("%d%d",&a,&b);

if(a==0||b==0||a>r1||b>r1)
printf("\nThe given row numbers do not match with that of the matrix\n");   //showing error messsage
else
{
	for(i=0;i<r1;i++)
	{
		temp=m2[a-1][i];      //row indexing starts from 0
		m2[a-1][i]=m2[b-1][i];
		m2[b-1][i]=temp;
	}
    printf("\nThe matrix after interchanging the two rows is :\n\n");

    for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		    printf("%.4f\t",m2[i][j]);
		}
		printf("\n");
	}
    FILE *fp2;
    fp2=fopen("data2.txt","w"); //writing the new matrix to a text file
    for(i=0;i<r1;i++)
    {
    for(j=0;j<c1;j++)
    {
    fprintf(fp2,"%0.4f\t",m2[i][j]);
    }
    fprintf(fp2,"\n");
    }
    fclose(fp2);
    printf("\nThe matrix with interchanged rows is now saved into a file named 'data2.txt'\n");
}
}
}


