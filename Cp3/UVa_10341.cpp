#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9


double p, q, r, s, t, u;



double f(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(int argc, char const *argv[])
{
    double lo, hi, mid, ans;
    
    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)!=EOF){
        lo=0.0;hi=1.0;mid=0.0; ans=0.0;
		if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0){
            printf("No solution\n");
            continue;
        }
        while (fabs(hi - lo) > EPS) {
            mid = (lo + hi) / 2.0;
            if (f(lo)*f(mid)<0 ) { ans = mid; hi = mid; }
            else lo = mid;
        }
        
        printf("%.4lf\n", ans);
        
    }
    return 0;
}
