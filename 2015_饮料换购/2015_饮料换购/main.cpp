//
//  main.cpp
//  2015_饮料换购
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int ans=n;
    int yu=0;
    while (n>=3) {
        yu = n%3;
        n /= 3;
        ans += n;
        n = n+yu;
    }
    cout<<ans<<endl;
    return 0;
}
