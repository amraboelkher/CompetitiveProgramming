
#include<bits/stdc++.h>
using namespace std;
int dp[7][12][7][2][2];
char A[7] , B[7];
int NA , NB;
int rec(int idx , int prev ,  int len , bool con1 , bool con2){
    if(idx == len)
        return con1 && con2;
    int &ret = dp[idx][prev][len][con1][con2];
    if(ret != -1)
        return ret;
    ret = 0;
    for(char i = 'A' ; i <= 'J' ; i ++){
        if( (i - 'A') == prev || abs((i - 'A') - prev) == 1) continue;
        char cur = i;
        if(!con1){
            if(cur >= A[idx] && ( con2 || cur <= B[idx]) ){
                ret += rec(idx + 1 , i - 'A' , len , cur > A[idx] , (con2 || cur < B[idx]) );
            }
        }
        else {
            if(cur <= B[idx] || con2){
                int k = rec(idx + 1 , i - 'A' , len , con1 , (con2 || cur < B[idx] ) );
                ret += k;
            }
        }
    }
    return ret;
}
int main()
{
    while(scanf("%s%s" , A , B) != EOF){
        NA = strlen(A) , NB = strlen(B);
        memset(dp , -1 , sizeof dp);
        int ret = 0;
        for(int i = NA; i <= NB; i ++){
            int tmp = rec(0 , 11 , i , (i > NA) , (i < NB));
            ret += tmp;
        }
        printf("%d\n" , ret);
    }
}
