/*#include <stdio.h>
int main(){
	int t,r,g,b,i,j,tmp;
	scanf("%d",&t);
	while(t){
		scanf("%d%d%d",&r,&g,&b);
		if(b<r){
			tmp=r;
			r=b;
			b=tmp;
		}
		if(b<g){
			tmp=g;
			g=b;
			b=tmp;
		}
		printf("%d\n",(b>r+g) ? r+g : b+(r+g-b)/2);	//最長長於另二之和  則為另二之和的天數
				//若最長短於另二之和  則最長分配完後  另二尚可互相組合 若多一則捨棄
				//最長+(另二和-最長)/2 == 最長+剩餘/2(無條件捨去) 
		t--;
	}
	return 0;
}*/





#include <stdio.h>
int main()
{
	int t, r, g, b, tmp;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d%d",&r,&g,&b);
		if(r>g){tmp = r; r = g; g = tmp;}
		if(g>b){tmp = g; g = b; b = tmp;}
		printf("%d\n",(r+g > b) ? b+((r+g)-b)/2 : r+g);
		
		t--;
	}
	return 0;
}
