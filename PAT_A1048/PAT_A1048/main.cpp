//
//  main.cpp
//  PAT_A1048
//
//  Created by VachelChen on 2020/6/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[100010];
int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    int left = 0;
    int right = n-1;
    while (left<right) {
        if (a[left] + a[right] == m) {
            cout<<a[left]<<" "<<a[right]<<endl;
            return 0;
        }
        else if (a[left] + a[right] <m) {
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}
