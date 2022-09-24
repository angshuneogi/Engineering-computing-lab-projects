#include<stdio.h>

#include<math.h>

#define pi 3.14159265



float function_yp(float u)

{

	float yp;

	yp=u;

	return yp;

}



float function_up(float x, float y)

{

	float up;

	up=6*cos(x)+2-y;

	return up;

}



float y_analytical(float x)

{

	float ana_y;

	ana_y=2*cos(x)-pi*sin(x)+3*x*sin(x)+2;

	return ana_y;

}





float u_analytical(float x)

{

	float ana_u;

	ana_u=-2*sin(x)-pi*cos(x)+3*sin(x)+3*x*cos(x);

	return ana_u;

}

int main()

{
	FILE *fp1;
	 fp1 = fopen("output3_part2.txt","w");
    if(fp1 == NULL)
    {
        printf("Source File Could Not Be Found\n");
    }
	else
	{

	float x,y,u,h,x0,y0,u0,f,g,L,y_ana[50],u_ana[50],y_arr[50],u_arr[50],esumu[50],esumy[50],euL2[50],eyL2[50];

	x0=0;

	y0=4;

	u0=-pi;

	L=pi;

	int N[50];

    N[0]=2;

    N[1]=5;

    N[2]=10;

    N[3]=15;

    N[4]=20;

    N[5]=25;

	int i,j;

	

	for(j=0;j<6;j++)

	{

	

	h=(L-x0)/N[j];

	

	

	float k1,k2,k3,k4,l1,l2,l3,l4;

	

	x=x0;

	y=y0;

	u=u0;

	

	y_arr[0]=y;

	u_arr[0]=u;

	

	for(i=0;i<=N[j];i++)

	{

		y_ana[i]=y_analytical(x);

		u_ana[i]=u_analytical(x);

	    x=x+h;

	}

	

	x=x0;

	esumu[j]=0;

	esumy[j]=0;

	for(i=1;i<=N[j];i++)

	{

		f=function_yp(u);

		k1=h*f;

		g=function_up(x,y);

		l1=h*g;

		f=function_yp(u+l1/2);

		k2=h*f;

		g=function_up(x+h/2,y+k1/2);

		l2=h*g;		

		f=function_yp(u+l2/2);

		k3=h*f;

		g=function_up(x+h/2,y+k2/2);

		l3=h*g;	

		f=function_yp(u+l3);

		k4=h*f;

		g=function_up(x+h,y+k3);

		l4=h*g;

		y=y+(k1+2*k2+2*k3+k4)/6;

		u=u+(l1+2*l2+2*l3+l4)/6;

		esumy[j]=esumy[j]+pow((y-y_ana[i]),2);

		esumu[j]=esumu[j]+pow((u-u_ana[i]),2);

		y_arr[i]=y;

		u_arr[i]=u;

		x=x+h;

	}

	

	eyL2[j]=pow(esumy[j],0.5)/N[j];

	euL2[j]=pow(esumu[j],0.5)/N[j];



}

	fprintf(fp1,"N\teyL2\t\teuL2\n");	

	for(j=0;j<6;j++)

	{

	

		fprintf(fp1,"%d\t",N[j]);

		fprintf(fp1,"%f\t",eyL2[j]);

        	fprintf(fp1,"%f\t",euL2[j]);		

		fprintf(fp1,"\n");

	}


}
fclose(fp1);
}


