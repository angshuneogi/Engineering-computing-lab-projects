#include<stdio.h>

#include<math.h>



float function_yp(float x, float y, float z)

{

	float yp;

	yp=2*x*pow(z,2)/y;

	return yp;

}



float function_zp(float y, float z)

{

	float zp;

	zp=y/pow(z,2);

	return zp;

}



float ana_y(float x)

{

	float y;

	y=pow(x,2);

	return y;

}



float ana_z(float x)

{

	float z;

	z=x;

	return z;

}



int main()

{
	FILE *fp1;
	fp1 = fopen("output2_part1.txt","w");
    if(fp1 == NULL)
    {
        printf("Source File Could Not Be Found\n");
    }
    else
	{
	float x0,y0,z0,L,x,y,z,h,f,g,y_arr[50],z_arr[50],y_ana[50],z_ana[50];

	x0=1;

	y0=1;

	z0=1;

	L=5;

	float N[50];

    N[0]=5;

    N[1]=10;

    N[2]=20;

	int i,j;

	float k1,k2,k3,k4,l1,l2,l3,l4;

	

	

	for(j=0;j<3;j++)

	{

	h=(L-x0)/N[j];	

	y_arr[0]=y0;

	z_arr[0]=z0;

	

	x=x0;

	for(i=0;i<=N[j];i++)

	{

		y_ana[i]=ana_y(x);

		z_ana[i]=ana_z(x);

        x=x+h;	

	}

  

   

	

	y=y0;

	z=z0;

	x=x0;

	for(i=1;i<=N[j];i++)

	{

		f=function_yp(x,y,z);

		k1=h*f;

		g=function_zp(y,z);

		l1=h*g;

		f=function_yp(x+h/2,y+k1/2,z+l1/2);

		k2=h*f;

		g=function_zp(y+k1/2,z+l1/2);

		l2=h*g;		

		f=function_yp(x+h/2,y+k2/2,z+l2/2);

		k3=h*f;

		g=function_zp(y+k2/2,z+l2/2);

		l3=h*g;	

		f=function_yp(x+h,y+k3,z+l3);

		k4=h*f;

		g=function_zp(y+k3,z+l3);

		l4=h*g;

		y=y+(k1+2*k2+2*k3+k4)/6;

		z=z+(l1+2*l2+2*l3+l4)/6;

		y_arr[i]=y;

		z_arr[i]=z;

		x=x+h;

		

	

	}

fprintf(fp1,"N\tAnalytical y\tRK4 y\t\tAnalytical z\tRK4 z\n");	

	for(i=0;i<=N[j];i++)

	{

		fprintf(fp1,"%d\t",i);

		fprintf(fp1,"%f\t",y_ana[i]);

		fprintf(fp1,"%f\t",y_arr[i]);

       		fprintf(fp1,"%f\t",z_ana[i]);

		fprintf(fp1,"%f\t",z_arr[i]);		

		fprintf(fp1,"\n");

	}

fprintf(fp1,"\n\n");

}
}
fclose(fp1);

}
