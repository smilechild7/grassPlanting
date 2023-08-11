#include<cstdio>
#include<math.h>

int main(){
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int n;
        scanf("%d",&n);
        int list[3][n]; 
        for (int j=0;j<n;j++){
            int x,y,r;
            scanf("%d %d %d",&x,&y,&r);
            list[0][j]=x;
            list[1][j]=y;
            list[2][j]=r;
        }
        int res=0;
        for (int j=0;j<n;j++){
            double l1 = sqrt((x1-list[0][j])*(x1-list[0][j])+(y1-list[1][j])*(y1-list[1][j]));
            double l2 = sqrt((x2-list[0][j])*(x2-list[0][j])+(y2-list[1][j])*(y2-list[1][j]));
            if (l1>list[2][j] && l2>list[2][j]){
                res+=0;
            } else if (l1<list[2][j] && l2<list[2][j]){
                res+=0;
            } else {
                res+=1;
            }
        }      
        printf("%d\n",res);
    }
}