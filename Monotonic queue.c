/*
#include <stdio.h>
#define MAX_N (int)1e5 + 10
typedef struct{
	int index, x;
}MQ;
int n, k;
int a[MAX_N];
MQ q[MAX_N];
void getmin()
{
	int front = 1, back = 0;
	for(int i=1;i<=n+1;i++)
	{
		if(q[front].index+k < i) front++;
		if(i > k) printf("%d%c",q[front].x," \n"[i == n+1]);
		if(i == n+1) break;
		while(front <= back && q[back].x >= a[i]) back--;
		back++;
		q[back].x = a[i];
		q[back].index = i;
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	getmin();
	return 0;
}
*/
// Monotone queue
// 單調隊列

#include <stdio.h>
#define MAX_N (int)1e5 + 10
int n, k;
int a[MAX_N], qidx[MAX_N];//a 儲存數陣列 qidx 儲存單調對列中各數在a中的位置
void MQ_min()
{
	int front = 0, back = 0;
	for(int i=1;i<=n+1;i++)//印出在a[i]前的框中極值如果  i到n+1是因為n+1前面的框才會包含a[n]
	{
		if(qidx[front]+k < i) front++;//如果最前標號已經出框 彈出
		if(i > k) printf("%d%c",a[qidx[front]]," \n"[i == n+1]);//若i已經大於框長 開始印
		if(i == n+1) break;//如果i == n+1 印完即可結束 不必繼續找極值
		while(front <= back && a[qidx[back]] >= a[i]) back--;
        //如果單調隊列中的數比新進者大 踢掉 若front>back則表全踢掉 back加回來存新進數
		back++;//踢過頭加回來
        qidx[back] = i;//qidx的back處(當前最後處)存下該數在a中的位置
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	MQ_min();
	return 0;
}
/*
//數組實現
#include <stdio.h>
#define MAXN 2000005

typedef struct {
    int index,x;//需要記錄單調隊列內每個數的入隊時間(index)和大小(x)
}Num;

int a[MAXN]; //原數組
Num q[MAXN]; //單調隊列 

int main(void){
    int n,m; //n表示序列長度，m表示滑動窗口長度
    int front,back; //front,back分別表示隊頭、隊尾位置
    //輸入
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    //問題解決
    front=1;
    back=0;//初始化隊頭隊尾位置，隊頭>隊尾表示隊空
    for (int i=1;i<=n+1;i++){
        //先輸出數a[i]前的最小值
        if (front>back) //q空，即a[i]前沒有元素
			;
            //printf("0 ");
        else { //否則判斷隊頭是否需要出隊並輸出範圍內的隊頭
            if (q[front].index+m<i) //隊頭已經超出滑動窗口範圍
                front++; // 彈出隊頭
            printf("%d ",q[front].x); //此時隊一定非空（想想為什麼）
        }
		if(i == n+1) break;
        while (front<=back && q[back].x>=a[i]) 
        //當隊列非空時，不斷彈出隊尾比當前元素大的元素
            back--;
        back++;
        q[back].x=a[i];
        q[back].index=i;//將當前元素入隊
        //注意：當前元素無論如何都會入隊（想想為什麼）
    }
    return 0;
}
*/
