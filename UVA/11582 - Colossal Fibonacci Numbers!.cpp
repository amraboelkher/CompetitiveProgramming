
#include<bits/stdc++.h>
using namespace std;
vector< int > A[1002];
void init(){
    for(int mod = 2; mod < 1002; mod ++){
        int a = 0 , b = 1 , c = (a + b) % mod;
        A[mod].push_back(a);
        A[mod].push_back(b);
        A[mod].push_back(c);
        while(b != 0 || c != 1){
            a = b , b = c;
            c = (a + b) % mod;
            A[mod].push_back(c);
        }
        A[mod].pop_back();
        A[mod].pop_back();
    }
}
long long pw(unsigned long long a , unsigned long long b , int mod){
    if(b == 0)return 1;
    long long res = pw(a , b / 2 , mod) % mod;
    res = (res * res) % mod;
    if(b & 1)
        res = (res * a) % mod;
    return res;
}
int main(){
    init();
    int n ;
    scanf("%d" , &n);
    while(n --){
        unsigned long long a , b , c;
        scanf("%llu%llu%llu" , &a , &b , &c);
        if(c == 1){
            puts("0");
            continue;
        }
        int sz = A[c].size();
        int idx = pw(a % sz , b , sz);
        printf("%lld\n" , A[c][idx]);
    }

}
