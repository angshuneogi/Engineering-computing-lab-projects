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
	 fp1 = fopen("output2_part2.txt","w");
    if(fp1 == NULL)
    {
        printf("Source File Could Not Be Found\n");
    }
    else
	{
	float x0,y0,z0,L,x,y,z,h,f,g,y_arr[50],z_arr[50],y_ana[50],z_ana[50],esumy[50],esumz[50],eyL2[50],ezL2[50];

	x0=1;

	y0=1;

	z0=1;

	L=5;

	int N[50];

    N[0]=2;

    N[1]=5;

    N[2]=10;

    N[3]=15;

    N[4]=20;

    N[5]=25;

	int i,j;

	float k1,k2,k3,k4,l1,l2,l3,l4;

	

	

	for(j=0;j<6;j++)

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

	

	esumy[j]=0;

	esumz[j]=0;

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

		esumy[j]=esumy[j]+pow((y-y_ana[i]),2);

		esumz[j]=esumz[j]+pow((z-z_ana[i]),2);

		y_arr[i]=y;

		z_arr[i]=z;

		x=x+h;

		

	

	}

	

	eyL2[j]=pow(esumy[j],0.5)/N[j];

	ezL2[j]=pow(esumz[j],0.5)/N[j];



	}

	fprintf(fp1,"N\teyL2\t\tezL2\n");

	for(j=0;j<6;j++)

	{

		fprintf(fp1,"%d\t",N[j]);

		fprintf(fp1,"%f\t",eyL2[j]);

        fprintf(fp1,"%f\t",ezL2[j]);

		fprintf(fp1,"\n");

	}


}
fclose(fp1);
}
