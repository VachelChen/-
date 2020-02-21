//
//  main.cpp
//  2016_生日蜡烛
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++){
            if(j*(i+i+j-1)/2 == 236)
                cout<<i<<" "<<j<<endl;
        }
    return 0;
}
