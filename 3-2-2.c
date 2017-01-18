#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NEURO 1000
#define PATTERN 4
#define STUDY 0.01

    int x1[PATTERN]={0,0,1,1};
    int x2[PATTERN]={0,1,0,1};
    int t[PATTERN]={0,1,1,0};

double Heaviside(double x){/*ヘビサイド関数*/

    if(x >= 0){
        return 1.0;
    }else{
        return 0.0;
            }
}

int CheckPattern(double v1[NEURO],double v2[NEURO],double v3[NEURO],double w[NEURO]){/*全パターンを入力し、正しいかどうかチェックする*/
    int sum,i,j;
    double z[NEURO];
    double y,err; 

    for(i=0;i<4;i++){
        for(j=0;j<NEURO;j++){
            z[j] = v1[j] * x1[i] + v2[j] * x2[i] + v3[j];
            z[j] = Heaviside(z[j]);
        }
        for(j=0;j<NEURO;j++){
            y += z[j] * w[j];
        }
        y = Heaviside(y);
        err = (double)t[i] - y;

        sum += pow((int)err,2); 
    }
    return sum;
}

int main(){
    int flag = 0,count = 0,i,j,test,n,m=0,sum=0;
    double v1[NEURO],v2[NEURO],v3[NEURO],w[NEURO],z[NEURO],y,err=0.0;

    srand((unsigned int) time(NULL));
 
    for(i=0;i<NEURO;i++){
        v1[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        v2[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        v3[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        w[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
    }

    while(count < 10000 || sum != 0 || i < PATTERN){
        sum = 0;
        flag = 0;
        for(j=0;j<NEURO;j++){
            z[j] = (double)x1[m] * v1[j] + (double)x2[m] * v2[j] + v3[j];
            if(j == NEURO-1){
                z[j] = 1.0;
                }else{
                z[j] = Heaviside(z[j]);
            }
            
            y += z[j] * w[j];
        }
        
        y = Heaviside(y);
        err = (double)t[m] - y;
        if(err != 0.0){
            for(n=0;i<NEURO;n++){
                w[n] += err * STUDY * z[n];
            }
            count++;
            flag = 1;
        }
        
        if(flag != 0){/*学習した後、教師データと照合する*/
            sum = CheckPattern(v1,v2,v3,w);
            printf("%d\n",sum);
            m = 0;
        }else{
            m++;
        }       
    }

    if(count >= 10000){
        printf("study faild");
    }else{
        printf("sucsess");
    }
    printf("renewal:%d times\n",count);
    
    return 0;
    
}
