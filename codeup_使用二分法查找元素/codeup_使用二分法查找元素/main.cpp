//
//  main.cpp
//  codeup_使用二分法查找元素
//
//  Created by VachelChen on 2020/3/4.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    while(cin>>n){
    int v[200];
    memset(v, 0, sizeof(v));
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    cin >> m;
    sort(v,v+n);
    //二分查找
    int ans = -1;
    int left = 0;
    int right = n-1;
    int mid = (left+right)/2;
    while(left <= right){
        if(v[mid] == m) {
            ans = mid;
            break;
        }
        else if(v[mid] > m){
            right = mid -1;
            mid = (left+right)/2;
        }
        else if(v[mid] < m){
            left = mid +1;
            mid = (left+right)/2;
        }
    }
        cout<<ans<<endl;}
    return 0;
}
