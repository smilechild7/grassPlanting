#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n;
        cin >> n;

        if(n<3){
            int ARR1,ARR2,ARR3;
            for(int j=0; j<n; j++){
                cin >> ARR1 >> ARR2 >> ARR3;
            }
            cout << "#" << i+1 << " " << -1 << endl; 
            continue;
        }

        int** arr= new int*[3];
        for(int j=0; j<3; j++){
            arr[j] = new int[n];
        } // 2차원 배열의 동적할당방법

        int** arr1= new int*[3];
        for(int j=0; j<3; j++){
            arr1[j] = new int[n];
        } // 2차원 배열의 동적할당방법
        
        int* max = new int[n];
        int sum=0;
        int maxSum=0;
        int a=0,b=0,c=0;
        for(int j=0; j<n; j++){
            cin >> arr[0][j] >> arr[1][j] >> arr[2][j];
            
            sum+= arr[0][j]+arr[1][j]+arr[2][j];
            
            max[j] = arr[0][j];
            if (max[j]<arr[1][j]){
                max[j] = arr[1][j];
            }
            if (max[j]<arr[2][j]){
                max[j] = arr[2][j];
            }

            maxSum+=max[j];

            arr1[0][j] = arr[0][j]-max[j];
            arr1[1][j] = arr[1][j]-max[j];
            arr1[2][j] = arr[2][j]-max[j];

            if(arr1[0][j]==0){
                a++;
            }
            if(arr1[1][j]==0){
                b++;
            }
            if(arr1[2][j]==0){
                c++;
            }
        }

        int s1,s2,s3;
        if(a!=0 && b!=0 && c!=0){
            cout << "#" << i+1 << " " << sum-maxSum << endl; 
        } else if(a==1||b==1||c==1){
            if (a==0){
                s1=0;
            }else if(b==0){
                s1=1;
            }else if(c==0){
                s1=2;
            }
            if (a==1){
                s2=0;
            }else if(b==1){
                s2=1;
            }else if(c==1){
                s2=2;
            }
            if (a>1){
                s3=0;
            }else if(b>1){
                s3=1;
            }else if(c>1){
                s3=2;
            }
            int mMax = -100000;
            for(int j=0; j<n; j++){
                if(arr1[s1][j]>mMax){
                    if(arr1[s2][j]==0){
                        continue;
                    }
                    mMax=arr1[s1][j];
                }
            }
            cout << "#" << i+1 << " " << sum-maxSum-mMax << endl; 
        } else if((a*b+b*c+c*a)!=0) {
            if (a==0){
                s1=0;
                s2=1;
                s3=2;
            } else if(b==0){
                s1=1;
                s2=0;
                s3=2;
            } else if(c==0){
                s1=2;
                s2=0;
                s3=1;
            }
            int mMax=-100000;
            for(int j=0; j<n; j++){
                if(arr1[s1][j]>mMax){        
                    mMax=arr1[s1][j];
                }
            }
            cout << "#" << i+1 << " " << sum-maxSum-mMax << endl; 
        } else {
            if(a>1){
                s3=0;
                s1=1;
                s2=2;
            }else if(b>1){
                s3=1;
                s1=0;
                s2=2;
            }else if(c>1){
                s3=2;
                s1=0;
                s2=1;
            }
            int index1;
            int mMax11=-100000;
            for(int j=0; j<n; j++){
                if(arr1[s1][j]>mMax11){
                    mMax11=arr1[s1][j];
                    index1=j;
                }
            }
            int mMax12=-100000;
            for(int j=0; j<n; j++){
                if(arr1[s2][j]>mMax12&&j!=index1){
                    mMax12=arr1[s2][j];
                }
            }
            int mMax1 = mMax11+mMax12;

            int index2;
            int mMax21=-100000;
            for(int j=0; j<n; j++){
                if(arr1[s2][j]>mMax21){
                    mMax21=arr1[s2][j];
                    index2=j;
                }
            }
            int mMax22=-100000;
            for(int j=0; j<n; j++){
                if(arr1[s1][j]>mMax22&&j!=index2){
                    mMax22=arr1[s1][j];
                }
            }
            int mMax2 = mMax21+mMax22;
            if (mMax1>mMax2){
                cout << "#" << i+1 << " " << sum-maxSum-mMax1 << endl; 
            } else {
                cout << "#" << i+1 << " " << sum-maxSum-mMax2 << endl;    
            }
        }
    }
    
}