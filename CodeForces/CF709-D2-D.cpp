#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
// -_-
int main()
{
    long long a00 , a01 , a10 , a11;
    scanf("%I64d%I64d%I64d%I64d" , &a00 , &a01 , &a10 , &a11);
    if(a01 + a10 + a00 + a11 == 0){
        puts("0");
        return 0;
    }
    long long r0 = 1 , r1 = 1;
    while(r0 * (r0 - 1) / 2 < a00)
        r0 ++;
    while(r1 * (r1 - 1) / 2 < a11)
        r1 ++;
    if(r0 * (r0 - 1) / 2 != a00 || r1 * (r1 - 1) / 2 != a11 ){
        puts("Impossible");
        return 0;
    }
    if(a11 + a01 + a10 == 0){
        for(int i = 0 ;i < r0 ;i ++)
            printf("0");
        return 0;
    }
    if(a00 + a01 + a10 == 0){
        for(int i = 0 ;i < r1; i ++)
            printf("1");
        return 0;
    }
    if( r1 * r0 != a01 + a10 ){
        puts("Impossible");
        return 0;
    }
    string res = "" ;
    for(int i = 0 ; i < r0 ;i ++)   res += "0";
    for(int i = 0 ; i < r1 ;i ++)   res += "1";
    long long R10  = r0 * r1 - a01 ;
    for(int i = r0 , idx = 0;i < r0 + r1 && R10 > 0; i ++ , idx ++){
        int sz = i - idx;
        if(sz >= R10){
            swap(res[i] , res[i - R10]);
            R10 = 0;
        }
        else {
            R10 -= sz;
            swap(res[i] , res[idx]);
        }
    }
    if(res.size() > MAX)    puts("Impossible");
    else    printf("%s\n" , res.c_str());
    return 0;
}
