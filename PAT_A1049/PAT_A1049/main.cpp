
#include <iostream>
using namespace std;
int main() {
    int n,left,right,now,ans = 0,a = 1;
    scanf("%d",&n);
    while (n/a) {
        left = n/(a*10);
        now = n/a %10;
        right = n%a;
        if(now == 0)    ans+=left*a;
        else if (now == 1)  ans+=left*a+right+1;
        else ans+=(left+1)*a;
        a *= 10;
    }
    printf("%d\n",ans);
    return 0;
}
