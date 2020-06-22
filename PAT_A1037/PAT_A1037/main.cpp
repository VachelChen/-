//
//  main.cpp
//  PAT_A1037
//
//  Created by VachelChen on 2020/6/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int nc,np;
int c[100010],p[100010];

int main(int argc, const char * argv[]) {
    scanf("%d" ,&nc);
    for (int i=0; i<nc; i++) {
        scanf("%d" ,&c[i]);
    }
    scanf("%d" ,&np);
    for (int i=0; i<np; i++) {
        scanf("%d" ,&p[i]);
    }
    sort(c, c+nc);
    sort(p, p+np);
    int ans=0;
    int x=0,y=0;
    while (c[x] < 0 && p[y]<0 && x<nc && y<np) {
        ans += c[x]*p[y];
        x++;y++;
    }
    x = nc -1; y = np -1;
    while (c[x] > 0 && p[y] > 0  && x>=0 && y>=0) {
        ans += c[x]*p[y];
        x--;y--;
    }
    cout<<ans<<endl;
    return 0;
}
