# jikken-2nd-pa-seputoron
include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NEURO 1000
#define PATTERN 4



int main(){
    int flag = 0,count = -1,i,j,test,n,m,sum=0,end=0;
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

    while(1){
        for(i=0;i<PATTERN;i++){
            for(j=0;j<NEURO;j++){
                z[j] = (double)x1[i] * v1[j] + (double)x2[i] * v2[j] + v3[j];
                if(j == NEURO-1){
                    z[j] = 1.0;
               }else if(z[j] >= 0.0){
                    z[j] = 1.0;
                }else{
                    z[j] = 0.0;
                }
                y += z[j] * w[j];
            }

            if(y >= 0.0){
                y = 1.0;
            }else{
                y = 0.0;
            }
            err = (double)t[i] - y;
            if(err != 0.0){
                for(n=0;i<NEURO;i++){
                    w[n] += err * 0.001 * z[n];
                    count++;
                }
                flag = 1;
            }

            if(flag != 0){/*学習した後、教師データと照合する*/
                for(n=0;n<PATTERN;n++){
                    for(m=0;m<NEURO;m++){
                        z[m] = ((double)x1[n] * v1[m]) + ((double)x2[n] * v2[m]) + v3[m];
                        if(j == NEURO-1){
                            z[m] = 1.0;
                        }else if(z[m] >= 0.0){
                            z[m] = 1.0;
                        }else{
                           z[m] = 0.0;
                        }
                        y += z[m] * w[m];
                    }

                    if(y >= 0.0){
                        y = 1.0;
                    }else{
                        y = 0.0;
                    }
                    err = (double)t[n] - y;
                    if(err != 0.0){
                        sum += pow(err,2);
                    }
                }
                if(sum == 0){
                    end = 1;
                    break;
                }else{
                    sum = 0;
                    i = 0;
                    flag = 0;
                }
            }
            if(end == 1){
                break;
            }
            if(count > 1000000){
                printf("study faild\n");
                end = 1;
                break;
            }
        }
        if(end == 1){
            break;
        }
    }
        printf("renewal:%d times\n",count);

        return 0;

}


