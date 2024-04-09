#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7
void main(){

int i,j;
int mt[N][M];
srand(time(NULL));

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {   
        *(&mt[0][0]+j+i*M) = 1+rand()%100;
        printf("%d ",*(&mt[0][0]+j+i*M));
    }
        printf("\n");
}
}
