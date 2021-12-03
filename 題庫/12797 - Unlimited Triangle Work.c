#include <stdio.h>
int main()
{
	int t, A, B, C, D, z, l_x, l_y, r_x, r_y;//l_x l_y 為圖左上交點  r_x r_y 為圖右下交點  
	long long int cnt = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&A,&B,&C,&D);
		for(z=C;z<=D;z++)
		{
			l_x = A; r_y = B;	//先定左上點x軸於A 定右下點y軸於B 
			l_y = z+1-l_x;		//左上點y軸 由極端邊長值減x軸之值 可得形成三角形之左點極限 
			if(l_y < B) l_y = B;//如果y軸 < B 表全y值皆可形成三角形 y軸改為B 
			else if(l_y > C){l_y = C; l_x = z+1-l_y;}//若超越上限C值則改成決定x值 y值則在上限	
			r_x = z+1-r_y;		//右下點一樣 只是改完先看x不行再看y 
			if(r_x < A) r_x = A;
			else if(r_x > B){r_x = B; r_y = z+1-r_x;}
			if(r_y <= C && l_x <= B) cnt += (B-l_x+1)*(C-l_y+1)+((B-l_x)+(B-r_x+1))*(l_y-r_y)/2;
		}//若最後是超越上限表不可能形成三角形 直接跳過累積環節	//算方形+梯形面積 
		printf("%lld\n",cnt);
		cnt = 0;
	}
	return 0;
}


/*
#include <stdio.h>
int main()
{
	int t;
	double a, b, c, d, i, lx, ly, rx, ry, ux,uy,urx,ury, j, ans;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		for(i=c;i<=d;i++)
		{
			lx = a; ly = b;
			rx = a; ry = b;
			ux =b,uy=c;
			urx=b,ury=c;
			j=3*i/2;
			if(ux+uy >= j) ux = j - c -1;
			if(urx+ury >= j) ury = j - b -1;
			if(ux < a) {ux = a;	uy = j-ux-1;}
			if(ury < b){ury = b;urx=j-ury-1;}
			
			if(lx+ly <= i) ly = i+1-a;
			if(rx+ry <= i) rx = i+1-b;
			if(ly > c){ly = c; lx = i+1-c;}
			if(rx > b){rx = b; ry = i+1-b;}

			if(lx <= b && ry <= c)
				ans += (b-lx+1)*(c-ly+1) + (b-lx + b-rx+1)*(ly-ry)/2;
			
			if(uy <b || urx<a)
				ans -= (c-b+1)*(b-a+1);
			else if((ux <= b && ury <= c))
				ans -=	(b-ux+1)*(c-uy) + (b-ux + b-urx)*(uy-ury+1)/2;
			//ans -= ((c-urx)*(b-ury+1) + (b-ury + b-uy)*(urx-ux+1)/2);
			
		}
		printf("%lld\n",(long long int)ans);
	}
	return 0;
}
*/

// wrong
/*
#include <stdio.h>
int main()
{
	int t;
	int a, b, c, d, i, lx, ly, rx, ry, ux,uy,urx,ury, j;
	long long int ans;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(i=c;i<=d;i++)
		{
			lx = a; ly = b;
			rx = a; ry = b;
			ux =b,uy=c;
			urx=b,ury=c;
			if(i%2 == 0)j=3*i/2;
			else j=3*(i+1)/2-1;
			if(ux+uy >= j) ux = j - c -1;
			if(urx+ury >= j) ury = j - b -1;
			if(ux < a) {ux = a;	uy = j-ux-1;}
			if(ury < b){ury = b;urx=j-ury-1;}
			
			if(lx+ly <= i) ly = i+1-a;
			if(rx+ry <= i) rx = i+1-b;
			if(ly > c){ly = c; lx = i+1-c;}
			if(rx > b){rx = b; ry = i+1-b;}

			if(lx <= b && ry <= c)
				ans += (b-lx+1)*(c-ly+1) + (b-lx + b-rx+1)*(ly-ry)/2;
			
			if(uy <b || urx<a)
				ans -= (c-b+1)*(b-a+1);
			else if((ux <= b && ury <= c))
				ans -=	(b-ux+1)*(c-uy) + (b-ux + b-urx)*(uy-ury+1)/2;
			//ans -= ((c-urx)*(b-ury+1) + (b-ury + b-uy)*(urx-ux+1)/2);
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/
