//
//  main.cpp
//  BJFU_261
//
//  Created by VachelChen on 2020/8/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        int a[maxn],b[maxn];
        int p=0,q=0;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x<0)
                b[q++] = x;
            else
                a[p++] = x;
        }
        for (int i=0; i<q; i++) {
            a[p++] = b[i];
        }
        cout<<a[0];
        for (int i=1; i<p; i++) {
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
