//
//  main.cpp
//  PAT_A1064
//
//  Created by VachelChen on 2020/6/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
int n;
int tree[maxn],v[maxn];

int y=0;
void createMidTree(int root){
    if(root >= n)   return;
    createMidTree(root*2+1);
    tree[root] = v[y++];
    createMidTree(root*2+2);
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    if (n == 0) {
        return 0;
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    sort(v, v+n);
    //新建树
    createMidTree(0);
    printf("%d",tree[0]);
    for (int i=1; i<n; i++) {
        printf(" %d",tree[i]);
    }
    return 0;
}
