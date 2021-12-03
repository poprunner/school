#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100;
int min_numbers[MAXNV]={0};
int main(void)
{
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
	
    filling(water, 0, nv);

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}
//********************************************//自己寫 

/*
void filling(int amount, int cur, int nv) 
{
	if(cur==nv) return;

	if(amount==0){ min=0; return;}
	else if(amount<0) return;

	while(1)
	{
		min_numbers[cur]++;		
		filling(amount-liters[cur],cur,nv);
		if(min==0) return;
		min_numbers[cur]--;
		
		filling(amount,cur+1,nv);
		if(min==0) return;
	}
}
*/

void filling(int amount, int cur, int nv) //amount 水剩餘量  cur 已用水瓶數 nv 水瓶種類數 
{
	int i;

	if(cur == min) return;				//如果cur >= 最低水瓶數 直接return 因為其不可能會是最小值 

	if(amount == 0)						//如果剛好用完 
	{
		min = cur;						//cur一定會是最小值 因為不是最小值會被上面的 if 擋掉 
		for(i=0;i<nv;i++)
        	min_numbers[i] = numbers[i];//將各種水瓶數量貼到 min_numbers[] 中 
		return;	
	}
	else if(amount < 0) return;			//如果小於0 代表水瓶容量超過水總量 直接返回 
	
	for(i=0;i<nv;i++){					//每種水瓶都裝看看 
		numbers[i]++;
		filling(amount-liters[i],cur+1,nv);
		numbers[i]--;					//裝完後記得 -- 再換用下種裝 
	}
}
