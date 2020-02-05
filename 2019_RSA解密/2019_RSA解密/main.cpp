#include<iostream>
using namespace std;
long long n,p,q,e,c,k,X,d;
 
long long fast_mul(long long x,long long d,long long mod){
    long long ans=0;
    x%=mod;d%=mod;
    while(d){
        if(d&1) ans=(ans+x)%mod;
        x<<=1;
        x%=mod;
        d>>=1;
    }
    return ans;
}
 
long long fast_pow(long long x,long long d,long mod){
    long long ans=1;
    x%=mod;
    while(d){
        if(d&1) ans=fast_mul(ans,x,mod);
        x=fast_mul(x,x,mod);
        d>>=1;
    }
    return ans;
}
int main()
{
    n=1001733993063167141;
    d=212353;c=20190324;
    for(long long i=2;i<n;i++){
        if(n%i==0) {
            q=i;
            p=n/q;
            break;
        }
    }
    printf("p=%lld   q=%lld\n",p,q);
    k=(p-1)*(q-1);
    for(e=1;;e++){
        if(fast_mul(d,e,k)==1) break;
    }
    printf("e=%lld\n",e);
    
    X=fast_pow(c,e,n);
    printf("x=%lld\n",X);
    return 0;
}

