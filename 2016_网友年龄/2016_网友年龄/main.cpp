//
//  main.cpp
//  2016_网友年龄
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int ans=1;
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            if((i*10+j)== (j*10+i)+27){
                cout<<"No."<<ans++<<endl;
                cout<<i*10+j<<endl;
            }
        }
    }
    return 0;
}
