/*#include <stdio.h>
int cnt;
void much(int m,int layg){//換瓶蓋函式 
	if((m+layg)<3)
		return;
	cnt+=(m/3);
	layg+=(m%3);
	if(layg>=3){
		layg-=3;//多累積再換一瓶 
		layg++;//那瓶的蓋子 
		cnt++;
	}
	much(m/3,layg);//蓋子數 
}
int main(void){
	int want,mtb;
	scanf("%d",&want);
	mtb=want/2;
	while(1){
		cnt+=mtb;
		much(mtb,0);
		if(cnt>=want)//大於等於想要的數量都可以 
		//如果只等於(像3就跑不出來，因為要馬得到2瓶 要馬就4瓶 不會有剛好3瓶 
			break;
		cnt=0;
		mtb++;
	}
	printf("%d\n",mtb);
	return 0; 
} */




#include <stdio.h>
int caps(int get,int remain)				//目前得到瓶數  目前在手的瓶蓋數  
{
	if(remain < 3) return get;				//如果剩下的瓶蓋不足3個 return 
	caps(get+remain/3,remain/3+remain%3);	//將在手瓶蓋全部換成飲料  並把蓋子全部收集起來 
}//目前瓶數+瓶蓋所換的飲料數  收集所換得飲料的蓋子加上上一批沒換完的蓋子 
int main()
{
	int n, i;
	scanf("%d",&n);
	i = n/2;								//從n/2開始試 
	while(caps(i,i) < n) i++;				//若換不滿 多買一瓶試看看 
	printf("%d\n",i);						//印出 
	return 0;
}
