#include<bits/stdc++.h>
using namespace std;
double A[21][21] , dp[21][(1 << 20) + 5];
bool vis[21][(1 << 20) + 1];
int n , m;
double rec(int idx,  int msk){
    if(idx == n)return 0.0;
    double &ret = dp[idx][msk];
    if(vis[idx][msk])return ret;
    vis[idx][msk] = 1;
    bool in = 0;
    for(int i = 0 ;i < m ;i ++){
        if(~msk & (1 << i)){
            double x = A[idx][i] + rec(idx + 1 , msk | (1 << i) ) ;
            if(!in)
                in = 1 , ret = x;
            else ret = min(ret , x);
        }
    }
    return ret;
}
int main()
{
    while(scanf("%d%d" , &n , &m) && (n | m)){
        for(int i = 0 ;i < n ;i ++){
            for(int l = 0 ;l < m ;l ++)
                scanf("%lf" , &A[i][l]);
            for(int l = 0 ;l < (1 << m); l ++)
                vis[i][l] = 0;
        }
        double ret = rec(0 , 0);
        ret /= (double)n;
        printf("%.2lf\n" , ret + 1e-9);
    }
}
