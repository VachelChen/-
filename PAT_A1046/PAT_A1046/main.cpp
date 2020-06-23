//
//  main.cpp
//  PAT_A1046
//
//  Created by VachelChen on 2020/6/23.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int n,m,sum=0;
int dis[100010]={0};

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&dis[i]);
        dis[i] += dis[i-1];
    }
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        int b,e;
        scanf("%d %d",&b,&e);
        if (b>e) {
            swap(b, e);
        }
        int temp = dis[e-1] - dis[b-1];
        cout<<min(temp,dis[n]-temp)<<endl;
    }
    return 0;
}
