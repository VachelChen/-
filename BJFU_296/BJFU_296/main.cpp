//
//  main.cpp
//  BJFU_296
//
//  Created by VachelChen on 2020/9/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

void Swap(char a[],int x,int y){
    char temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        char a[maxn];
        if(!n) break;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int FirstWhite=0,i=0,LastWhite=n-1;
        while (i<=LastWhite) {
            if (a[i] == 'R') {
                Swap(a, FirstWhite, i);
                FirstWhite++;
                if(i<FirstWhite)
                    i = FirstWhite;
            }
            if (a[i] == 'W') {
                i++;
            }
            if (a[i] == 'B') {
                Swap(a, LastWhite, i);
                LastWhite--;
            }
        }
        cout<<a[0];
        for (int i=1; i<n; i++) {
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
