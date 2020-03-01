//
//  main.cpp
//  codeup_查找元素_统计同城学生人数
//
//  Created by VachelChen on 2020/3/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while (n) {
        int a[1000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int target;
        cin >>target;
        int ans=0;
        for (int i=0; i<n; i++) {
            if(a[i] == target)
                ans++;
        }
        cout<<ans<<endl;
        cin >> n;
    }
    return 0;
}
