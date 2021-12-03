/*#include <stdio.h>
int data[1000][1000];
int main()
{
	int n, i, j, max ,min;								
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) scanf("%d",&data[i][j]);
	for(i=0;i<n;i++)
	{	
		max = -1;
		for(j=0;j<n;j++)
			if(data[i][j] > max) max = data[i][j];
		printf("%d%c",max," \n"[i == n-1]);
	}
	for(j=0;j<n;j++)
	{		
		min = 50001;
		for(i=0;i<n;i++)
			if(data[i][j] < min) min = data[i][j];
		printf("%d%c",min," \n"[j == n-1]);
	}
	return 0;
}*/

#include <stdio.h>
int a[1000][1000];
int main()
{
	int n, i, j, rmax, cmin;
	scanf("%d",&n);
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);	
	for(i=0;i<n;i++)
	{
		rmax = 0;
		for(j=0;j<n;j++) if(a[i][j] > rmax) rmax = a[i][j];
		printf("%d%c",rmax," \n"[i == n-1]);
	}
	for(j=0;j<n;j++)
	{
		cmin = 60000;
		for(i=0;i<n;i++) if(a[i][j] < cmin) cmin = a[i][j];
		printf("%d%c",cmin," \n"[j == n-1]);
	}
	return 0;
 } 
