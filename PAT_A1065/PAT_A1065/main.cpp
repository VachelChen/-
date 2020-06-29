//
//  main.cpp
//  PAT_A1065
//
//  Created by VachelChen on 2020/6/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long sum = a+b;
        if (a>0 && b>0 && sum<0) {
            printf("Case #%d: true\n",i+1);
        }
        else if(a<0 && b<0 && sum>=0){
            printf("Case #%d: false\n",i+1);
        }
        else if(sum > c){
            printf("Case #%d: true\n",i+1);
        }
        else{
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}
