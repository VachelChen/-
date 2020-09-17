//
//  main.cpp
//  BJFU_297
//
//  Created by VachelChen on 2020/9/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct {
    int *elem;
    int length;
}Sqlist;

void Init(Sqlist &l,int n){
    l.elem = new int[n];
    l.length = n;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n) break;
        Sqlist l;
        Init(l,n);
        for (int i=0; i<n; i++) {
            cin >> l.elem[i];
        }
        int FirstP = 0;
        for (int i=0; i<n; i++) {
            if(l.elem[i]<0){
                int temp = l.elem[i];
                l.elem[i] = l.elem[FirstP];
                l.elem[FirstP] = temp;
                FirstP++;
            }
        }
        cout<<l.elem[0];
        for (int i=1; i<n; i++) {
            cout<<" "<<l.elem[i];
        }
        cout<<endl;
    }
    return 0;
}
