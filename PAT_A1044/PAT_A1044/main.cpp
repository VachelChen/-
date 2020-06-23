//
//  main.cpp
//  PAT_A1044
//
//  Created by VachelChen on 2020/6/23.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;

struct ans{
    int head;
    int tail;
};

int n,m;
int sum[maxn]={0};
vector<ans> v;


int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = sum[n];
    for (int i=1; i<=n; i++) {
        int left = i;
        int right = n;
        int mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (sum[mid] - sum[i-1] >= m)    right = mid-1;
            else
                left = mid +1;
        }
        if (sum[left] - sum[i-1] >= m) {
            if (sum[left] - sum[i-1] < minans) {
                minans = sum[left] - sum[i-1];
                v.clear();
                v.push_back({i,left});
            }
            else if(sum[left] - sum[i-1] == minans){
                v.push_back({i,left});
            }
        }
    }
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].head<<"-"<<v[i].tail<<endl;
    }
    return 0;
}
