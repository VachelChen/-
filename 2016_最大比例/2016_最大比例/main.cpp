#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const int N=110;
const ll MAX=1000000000000;
ll a[N];

ll gcd(ll a,ll b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

struct Frac
{
    ll up,dw;
    Frac() {}
    Frac(ll a,ll b) {
        if (a==0) {
            up=0;dw=1;
            return;
        }
        ll g=gcd(a,b);
        up=a/g;dw=b/g;
    }
    bool operator <(const Frac &b) const {
        return up*b.dw<dw*b.up;
    }
    bool operator ==(const Frac &b) const {
        return !((*this)<b)&&!(b<(*this));
    }
    Frac operator /(const Frac &b) {
        return Frac(up*b.dw,dw*b.up);
    }
    void print() {
        printf("%I64d/%I64d\n",up,dw);
    }
} f[N];

int main()
{
//    int n;
//    scanf("%d",&n);
//    for (int i=0;i<n;i++) {
//        scanf("%I64d",&a[i]);
//    }
//    sort(a,a+n);
//    n=unique(a,a+n)-a-1;
//    for (int i=0;i<n;i++) {
//        f[i]=Frac(a[i+1],a[i]);
//    }
//    Frac ans(MAX,1);
//    while (n>1) {
//        sort(f,f+n);
//        if (f[0]<ans) ans=f[0];
//        n=unique(f,f+n)-f-1;
//        for (int i=0;i<n;i++) {
//            f[i]=f[i+1]/f[i];
//        }
//    }
//    if (f[0]<ans) ans=f[0];
//    ans.print();
    cout<<(1/10000000 * log(1/10000000)/log(2) + (1-1/10000000) * log(1-1/10000000)/log(2))*-1<<endl;
    return 0;
}
