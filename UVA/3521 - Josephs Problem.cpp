#include<iostream>
using namespace std;

long long sum(int x){
    return x * 1LL * (x + 1) / 2;
}

long long solve(int n , int k){
    k = min(n  , k);
    long long res = 0 , mn = k , mx = 0;
    for(long long i = 1; i * i <= n ; i ++){
        mx = i;
        long long left = n / (i + 1) , right = min(1LL * k , n / i);
        if(left >= right)
            continue;
        mn = left;
        res += (i * 1LL * (sum(right) - sum(left) ) );
    }
    for(int i = 1;i <= mn ;i ++)
        res += ( (n / i) *1LL* i ) ;
    return res;
}
int main()
{
    int n , k;
    while(scanf("%d%d" , &k , &n) != EOF){
        long long res = n *1LL* k - solve(n , k);
        printf("%lld\n" , res);
    }
}
//lets solve the problem :D
//we have summation from 1 : m (n % i) which equal to sum i [1 : m] (n - floor(n / i) * i)
//which equal to n * m - sum i [1 : m] (floor(n / i) * i)
//and we also know that whenever the value of i > n this result will equal to zero which means we will stop at min(n , m)
//then the equation becomes n * m - sum i [1 : min(n , m)] (floor(n / i) * i)
//alright , right now we have two cases either floor(n / i) <= sqrt(n) or i <= sqrt(n) we will calculate each one :
//case 1 :
//floor(n / i) <= sqrt(n)
//we will try to reach to some regions from 1 : sqrt(n) such that each i will equal to floor(n / i) after the sqrt(n)
//through some formula which is
//for_each i I will get the right margin clearly through min( m ,n / i) and getting the left margin
//through n / (i + 1) + 1 so clearly  all these numbers from left : right will have the same floor(n / i)
//then I have left with the sum(left : right) which can be easily done through n * (n + 1) / 2
//we will mantian the smallest value for the left to ensure there isnt anything that we will calculate twice for 2nd case
//case 2:
//we will just loop through the min value that we have gotten and calculate sum for all i = 1 : min  (n / i) * i
