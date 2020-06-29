//
//  main.cpp
//  PAT_A1058
//
//  Created by VachelChen on 2020/6/26.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct currency{
    int g,s,k;
};

int main(int argc, const char * argv[]) {
    currency a,b;
    scanf("%d.%d.%d",&a.g,&a.s,&a.k);
    scanf("%d.%d.%d",&b.g,&b.s,&b.k);
    a.k = a.k + b.k;
    int sj = a.k/29;
    a.k = a.k % 29;
    
    a.s = a.s + b.s + sj;
    int gj = a.s/17;
    a.s = a.s % 17;
    
    a.g = a.g + b.g + gj;
    cout<<a.g<<"."<<a.s<<"."<<a.k<<endl;
    return 0;
}
