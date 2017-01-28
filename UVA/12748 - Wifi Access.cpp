#include<bits/stdc++.h>
using namespace std;
int X[200] , Y[200] , R[200];
int sq(int x){
    return x * x;
}
bool check(int x , int y , int idx){
    return sq(x - X[idx]) + sq(y - Y[idx]) <= R[idx] * R[idx];
}
int main()
{
    int t , T = 0;
    scanf("%d" , &t);
    while(t --){
        int n , L;
        scanf("%d%d" , &n , &L);
        for(int i = 0; i < n ; i ++)
            scanf("%d%d%d" , &X[i] , &Y[i] , &R[i]);
        printf("Case %d:\n" , ++T);
        for(int i = 0 ;i < L; i ++){
            int a , b ;
            scanf("%d%d" , &a , &b);
            bool ret = 0;
            for(int l = 0 ;l < n ;l ++){
                ret |= check(a , b , l);
            }
            if(ret)puts("Yes");
            else puts("No");
        }
    }
}
