//
//  main.cpp
//  BJFU_299
//
//  Created by VachelChen on 2020/9/14.
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
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            int x=0;
            for (int j=0; j<n; j++) {
                if(a[j]<a[i])
                    x++;
            }
            b[x] = a[i];
        }
        cout<<b[0];
        for (int i=1; i<n; i++) {
            cout<<" "<<b[i];
        }
        cout<<endl;
    }
    return 0;
}
