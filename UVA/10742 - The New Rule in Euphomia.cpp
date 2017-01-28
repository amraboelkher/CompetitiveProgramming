#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 2;
bool P[MAXN];
int A[MAXN] , idx;
long long Solve(int no){
    long long res = 0;
    for(int i = 0; i < idx; i ++){
        int rem = no - A[i];
        if(rem < 0)
            break;
        int L = i + 1 , R = upper_bound(A , A + idx , rem) - A;
        if(R >= L)
            res += (R - L);
    }
    return res;
}
int main()
{
    for(int i = 2; i < MAXN ;i ++){
        if(!P[i]){
            A[idx ++] = i;
            for(int l = i ; l < MAXN; l += i)
                P[l] = 1;
        }
    }
    int n;
    int T = 0;
    while(scanf("%d" , &n) , n){
        long long res = Solve(n);
        printf("Case %d: %lld\n" ,++T ,  res);
    }

}
