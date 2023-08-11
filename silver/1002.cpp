#include<cstdio>
#include<cmath>
int main(void){
    int testT;
    scanf("%d",&testT);
    int x1,y1,r1,x2,y2,r2;

    for (int i=0;i<testT;i++){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    double len;
    len = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double R1 = r1;
    double R2 = r2;
    double ls[] = {R1 , R2, len};
    for (int i=0;i<sizeof(ls)/sizeof(double);i++){
        for (int j = i;j<sizeof(ls)/sizeof(double)-i;j++){
            if (ls[i]<ls[i+j]){
            double temp = ls[i];
            ls[i] = ls[i+j];
            ls[i+j] = temp;
        }
        }
    }
    if (x1==x2&y1==y2&r1==r2){
        printf("%d\n",-1);
    } else if (ls[0]>ls[1]+ls[2]){
        printf("%d\n",0);
    } else if (ls[0]==ls[1]+ls[2]){
        printf("%d\n",1);
    } else {
        printf("%d\n",2);
    }
    }
    return 0;
}