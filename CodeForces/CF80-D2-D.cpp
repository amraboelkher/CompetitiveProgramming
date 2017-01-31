
#include<stdio.h>

int main()
{
    double a , b;
    int n ;
    scanf("%d" , &n);
    while(n --){
        scanf("%lf%lf" , &a , &b);
        if(b == 0)printf("%.12lf\n" , 1.0);
        else if(a == 0)printf("%.12lf\n" , 0.5);
        else {
            if(a <= 4 * b)
                printf("%.12lf\n" , 0.5 + a / (b * 16.0) );
            else printf("%.12lf\n" , (a - b) / a );

        }

    }


}
