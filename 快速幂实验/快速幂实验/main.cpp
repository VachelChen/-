//
//  main.cpp
//  快速幂实验
//
//  Created by VachelChen on 2020/2/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    long long a,b,ans;
    std::cin>>a>>b;
    ans=1;
    while (b!=0) {
        if((b&1) == 1){
            ans=ans*a;
        }
        a = a*a;
        b>>=1;
    }
    std::cout<<ans<<std::endl;
    return 0;
}
