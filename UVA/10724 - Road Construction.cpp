#include<bits/stdc++.h>
using namespace std;
int X[60] , Y[60] , N , M;
double Dis[2][60][60];
bool A[60][60];
struct node{
    double dis , d;
    int x , y;
    node(double dis , double d , int x , int y): dis(dis) , d(d) , x(x) , y(y) {}
    const bool operator < (const node &other) const {
        if(dis != other.dis)
            return dis > other.dis;
        if(d != other.d)
            return d < other.d;
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};
int sq(int x){
    return x * x;
}
double get(int i , int l){
    return sqrt(sq(X[i] - X[l]) + sq(Y[i] - Y[l]));
}
void run(int x){
    for(int i = 0 ;i < N ;i ++)
        for(int l = 0 ;l < N ;l ++){
            Dis[x][i][l] = 1e9;
            if(A[i][l] || i == l) Dis[x][i][l] = get(i , l);
        }
    for(int k = 0 ;k < N ;k ++)
        for(int i = 0; i < N ;i ++)
            for(int l = 0 ;l < N ;l ++)
                Dis[x][i][l] = min(Dis[x][i][l] , Dis[x][i][k] + Dis[x][k][l]);
}
double calc(int i , int l){
    run(0);
    A[i][l] = 1;
    run(1);
    A[i][l] = 0;
    double res = 0;
    for(int i = 0 ;i < N ;i ++)
        for(int l = 0 ;l < N ;l ++)
            res += Dis[0][i][l] - Dis[1][i][l];
    return res;
}
pair<int , int > solve(){
    vector< node > S;
    for(int i = 0 ;i < N ;i ++){
        for(int l = i + 1; l < N ;l ++){
            if(!A[i][l]){
                double res = calc(i , l);
                if(res - 1.0 > 1e-8)
                    S.push_back(node(res , get(i , l) , i , l));
            }
        }
    }
    sort(S.begin() , S.end() );
    if(S.size())
        return make_pair(S[0].x , S[0].y);
    return make_pair(-1 , -1);

}
int main()
{
    while(~scanf("%d%d" , &N , &M) && N | M){
        memset(A , 0 , sizeof A);
        for(int i = 0 ; i< N ; i ++)
            scanf("%d%d" , &X[i] , &Y[i]);
        while(M --){
            int a , b;
            scanf("%d%d" , &a , &b);
            A[a - 1][b - 1] = A[b - 1][a - 1] = 1;
        }
        pair<int , int > res = solve();
        if(res.first == -1)
            puts("No road required");
        else
            printf("%d %d\n" , ++res.first , ++res.second);
    }
}
