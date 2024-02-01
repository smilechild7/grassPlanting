#include <iostream>

using namespace std;

int al[] = {0,0}, bl[] = {0,0};

void getLocation(int n,int nl[]){
    int num=1;
    int i=1;
    while(n>num){
        i++;
        num+=i;
    }
    int distance = num-n;
    int x = distance + 1;
    int y = i - distance;
    nl[0] = x;
    nl[1] = y;
}

int change(int n){
    if(n<0){
        n=-n;
    }
    return n;
}

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        
        int a,b;
        cin >> a >> b;

        getLocation(a,al);
        getLocation(b,bl);
        int k=0;
        if((al[0]-bl[0])*(al[1]-bl[1])<0){
            if(change(al[0]-bl[0])>change(al[1]-bl[1])){
                k = change(al[1]-bl[1]);
            }else{
                k = change(al[0]-bl[0]);
            }
        }

        int res = change(al[0]-bl[0]) + change(al[1]-bl[1])-k;
        cout << "#" << i+1 << " " << res << endl;
    }
}
