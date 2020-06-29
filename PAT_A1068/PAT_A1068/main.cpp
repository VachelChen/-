
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;

int n,m;
int a[maxn];
bool has[maxn][110] = {false};
int dp[maxn][110] = {0};
//取前i个数，在能取的价值小于等于m的情况下能屈能取的最大价值。

bool cmp(int a,int b){
    return a > b;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d",&a[i]);
    }
    
    sort(a+1,a+1+n,cmp);

    for (int i = 1; i <= n; i++)
    {
        //边界设定
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m; j++)
        {
            int sum = dp[i-1][j-a[i]]+a[i];
            if (sum >= dp[i-1][j])
            {
                dp[i][j] = sum;
                has[i][j] = true;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if (dp[n][m] == m)
    {
        vector<int> v;
        while(m){
            while(!has[n][m]){
                n--;
            }
            v.push_back(a[n]);
            m -= a[n];
            n--;
        }
        for (int i = 0; i < v.size()-1; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<v[v.size()-1]<<endl;
    }
    else
        printf("No Solution\n");
    return 0;
}
