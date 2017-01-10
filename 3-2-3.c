# jikken-2nd-pa-seputoron
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NEURO 10000


int main(){
    int flag = 0,count = -1,i,test,n,sum=0;
    double v1[NEURO],v2[NEURO],v3[NEURO],w[NEURO],z[NEURO],y,err=0.0;
    int x1[4]={0,0,1,1};
    int x2[4]={0,1,0,1};
    int t[4]={0,1,1,0};

    srand((unsigned int) time(NULL));
    for(i=0;i<NEURO;i++){
        v1[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        v2[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        v3[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
        w[i] = ((double)rand() / ((double)RAND_MAX + 1)) * 2 - 1;
    }

    while(flag != 1){
        for(n=0;n<4;n++){
            for(i=0;i<NEURO;i++){
                z[i] = x1[n] * v1[i] + x2[n] * v2[i] + v3[i];
                if(z[i] > 0.0){
                    z[i] = 1.0;
                }else{
                    z[i] = 0.0;
                }
 }
            z[NEURO - 1] = 1.0;
            for(i=0;i<NEURO;i++){
                y += z[i] * w[i];
            }

    if(y > 0.0){
        y = 1.0;
    }else{
        y = 0.0;
}
    err = (double)t[n] - y;
    if(err < 0.0){
        for(i=0;i<NEURO;i++){
        w[i] -= (0.1) * z[i];
        sum += pow(err,2);
        count++;
        }
    }
    else if(err > 0.0){
        for(i=0;i<NEURO;i++){
        w[i] += (0.1) * z[i];
        sum += pow(err,2);
        count++;
        }
    }else{

     }
    }
        if(sum == 0){
            flag = 1;
        }
       }
        if(count > 10000){
            printf("study faild\n");

            break;
    }
    }
    printf("renewal:%d times\n",count);

    return 0;
}

