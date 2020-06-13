//
//  main.cpp
//  PAT_A1019
//
//  Created by VachelChen on 2020/6/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 10010;
bool flag = true;
int a[maxn];

int main(int argc, const char * argv[]) {
    int n,b;
    int index = 0;
    cin >> n >> b;
    while (n >= b) {
        a[index] = n%b;
        n /= b;
        index++;
    }
    a[index] = n;
    for (int i=0; i<=index; i++) {
        if (a[i] != a[index-i]) {
            flag = false;
        }
    }
    if (flag) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    cout<<a[index];
    for (int i=index-1; i>=0; i--) {
        cout<<" "<<a[i];
    }
    return 0;
}
