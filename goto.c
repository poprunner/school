#include <stdio.h>
int main()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                printf("%d ",i*100+j*10+k);
                if(i*100+j*10+k > 100) goto pop_out;
            }
        }
    }
    pop_out: printf("test succeed.\n");
    return 0;
}
