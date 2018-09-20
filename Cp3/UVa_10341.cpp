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
        
        while (fabs(hi - lo) > EPS) {
            mid = (lo + hi) / 2.0;
            if (f(lo)*f(mid)<0 ) { ans = mid; hi = mid; }
            else lo = mid;
        }
        if( fabs(f(ans))<1e-5)
            printf("%.4lf\n", ans);
        else
            cout<< "No solution"<<endl;
        
    }
    return 0;
}
