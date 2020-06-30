//
//  main.cpp
//  PAT_A1070
//
//  Created by VachelChen on 2020/6/30.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake{
    double inventory;
    double price,sprice;
}moon[1010];

int n,m;

bool cmp(mooncake a,mooncake b){
    return a.sprice < b.sprice;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%lf",&moon[i].inventory);
    }
    for (int i=0; i<n; i++) {
        scanf("%lf",&moon[i].price);
        moon[i].sprice = 1.0*moon[i].inventory/moon[i].price;
    }
    sort(moon, moon+n, cmp);
    double ans = 0;
    int index = 0;
    
    while (m && index<n) {
        if (moon[index].inventory <= m) {
            m -= moon[index].inventory;
            ans += moon[index].price;
        }
        else{
            ans +=  (moon[index].price*(1.0*m/moon[index].inventory));
            m = 0;
            break;
        }
        index++;
    }
    printf("%.2lf\n",ans);
    return 0;
}
