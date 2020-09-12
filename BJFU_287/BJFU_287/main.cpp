//
//  main.cpp
//  BJFU_287
//
//  Created by VachelChen on 2020/9/10.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        int a[maxn];
        for (int i=0;i<n; i++) {
            cin >> a[i];
        }
        int target;
        cin >> target;
        int low = 0;
        int high = n;
        bool flag = false;
        while (low <= high) {
            int mid = (low + high)/2;
            //cout<<"mid:"<<mid<<endl;
            if (a[mid] == target) {
                flag = true;
                break;
            }
            else if(a[mid]>target){
                high = mid - 1;
            }
            else if (a[mid]<target){
                low = mid + 1;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
