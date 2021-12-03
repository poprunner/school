#include <stdio.h>
#include "function.h"		//要記得 include "function.h" 
int cmpde( const void*, const void*);				//兩種比較方式 降 
int cmpas( const void*, const void*);				//升 
void sortGrade(Grade *gList, int n, char *order)
{
	int i;
	for( i = 0; i < n; i++)		//先把total加出來 
		gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
	if(order[0] == 'd')			//如果首字母是 d 則代表 descending 
		qsort( gList, n, sizeof(Grade), cmpde);//用 qsort  陣列，個數，大小，比較方法 
	else
		qsort( gList, n, sizeof(Grade), cmpas);
}
int cmpde( const void *ap, const void *bp)		//降序比較法 
{
	Grade a = *(Grade*)ap;						//先轉型為變數 (直接用 a.total) 
	Grade b = *(Grade*)bp;
	if(a.total < b.total)						//如果 a < b 則換 (越前面要越大) 
		return 1;
	else if(a.total == b.total)					//如果相等 比較下一順位 
	{
		if(a.Chinese < b.Chinese)
			return 1;
		else if(a.Chinese == b.Chinese)
		{
			if(a.English < b.English)
				return 1;
			else if(a.English == b.English)
			{
				if(a.math < b.math)
					return 1;
				else if(a.math == b.math)
				{
					if(a.science < b.science)
						return 1;
					else if(a.science == b.science)
					{
						if(a.ID > b.ID)			//ID永遠用升序 
							return 1;
					}
				}
			}
		}
	}
	return 0;									//如果不符合上述條件就不用換 
}
int cmpas( const void *ap, const void *bp)		//升序比較法(與降序只差在 < 變 > ) 
{
	Grade a = *(Grade*)ap;
	Grade b = *(Grade*)bp;
	if(a.total > b.total)
		return 1;
	else if(a.total == b.total)
	{
		if(a.Chinese > b.Chinese)
			return 1;
		else if(a.Chinese == b.Chinese)
		{
			if(a.English > b.English)
				return 1;
			else if(a.English == b.English)
			{
				if(a.math > b.math)
					return 1;
				else if(a.math == b.math)
				{
					if(a.science > b.science)
						return 1;
					else if(a.science == b.science)
					{
						if(a.ID > b.ID)
							return 1;
					}
				}
			}
		}
	}
	return 0;
}
