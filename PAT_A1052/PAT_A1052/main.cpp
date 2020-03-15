//
//  main.cpp
//  PAT_A1052
//
//  Created by VachelChen on 2020/3/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct node{
    int address,key,next;
    bool flag;
}n[maxn];

bool cmp(node a,node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;
    }
    else{
        return a.key < b.key;
    }
}

int main(int argc, const char * argv[]) {
    for (int i=0; i<maxn; i++) {
        n[i].flag = false;
    }
    int num,start;
    cin >> num >> start;
    for(int i=0; i < num; i++){
        int address,key,next;
        cin >> address >> key >> next;
        n[address].address = address;
        n[address].key = key;
        n[address].next = next;
    }
    int cnt = 0;
    for (int i=start; i!=-1; i=n[i].next) {
        n[i].flag = true;
        cnt++;
    }
    if(cnt == 0){
        cout<<"0 -1"<<endl;
    }
    else{
        sort(n,n+maxn,cmp);
        cout<<cnt;
        printf(" %05d\n",n[0].address);
        for(int i=0;i<cnt-1;i++){
            printf("%05d ",n[i].address);
            cout<<n[i].key;
            printf(" %05d\n",n[i+1].address);
        }
        printf("%05d ",n[cnt-1].address);
        cout<<n[cnt-1].key;
        cout<<" -1"<<endl;
    }
    return 0;
}
