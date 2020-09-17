//
//  main.cpp
//  BJFU_298
//
//  Created by VachelChen on 2020/9/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

int TwoPoint(int a[],int low,int high,int key){
    while (low<=high) {
        while (a[low]>key && a[high]<key) {
            low++;
            high--;
        }
        while (low<=high && a[low]<key) {
            low++;
        }
        if (a[low] == key) {
            return low;
        }
        while (low<=high && a[high]>key) {
            high--;
        }
        if (a[high] == key) {
            return high;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        int a[maxn];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int key;
        cin >> key;
        //two point
        int low = 0,high = n-1;
        int ans = TwoPoint(a,low,high,key);
        if (ans) {
            cout<<ans+1<<" "<<key<<endl;
        }
        else{
            cout<<"not find"<<endl;
        }
    }
    return 0;
}
