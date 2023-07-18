//Selection Sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;
void sSort(int *a,int n)
{
	int j,min;
	for(int i = 0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			c++;
			if(a[j]<a[min])
			{
				min=j;
				
			}
		}
		int t=a[min];
		a[min]=a[i];
		a[i]=t;
	}
}
void writeCount(int n,FILE *fp)
{
	fprintf(fp,"%d\t%d\n",n,c);
	c=0;
}
void writeArr(int *a,int n,FILE *fp)
{	
	fprintf(fp,"Array : \n");
	for(int i = 0;i<n;i++)
		fprintf(fp,"%d\t",a[i]);
	fprintf(fp,"\n");
}
void recordCount(int *a,int n,FILE *f,FILE *fp)
{
	writeArr(a,n,f);
	sSort(a,n);
	writeCount(n,fp);
}
void main()
{
	FILE *f=fopen("SSArrayInfo.txt","w");
	FILE *fc=fopen("SScount.txt","w");
	int *a;srand(time(0));
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		a[0]=rand()%100;
		for(int i=1;i<n;i++)
			a[i]=a[i-1]+rand()%10;
		recordCount(a,n,f,fc);
	}
	fclose(fc);
	fclose(f);
	FILE *fg = fopen("SSplot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"n\"\nset ylabel \"t\"\nplot \"SScount.txt\" w l smooth bezier ti \"SSort\"\nset term png\nset output \"SSG.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"SSplot.gnu\"");
system("eog SSG.png");
}
