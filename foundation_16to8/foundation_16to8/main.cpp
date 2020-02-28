//
//  main.cpp
//  foundation_16to8
//
//  Created by VachelChen on 2020/2/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        string two = "";
        
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case '0': two+="0000"; break;
                case '1': two+="0001"; break;
                case '2': two+="0010"; break;
                case '3': two+="0011"; break;
                case '4': two+="0100"; break;
                case '5': two+="0101"; break;
                case '6': two+="0110"; break;
                case '7': two+="0111"; break;
                case '8': two+="1000"; break;
                case '9': two+="1001"; break;
                case 'A': two+="1010"; break;
                case 'B': two+="1011"; break;
                case 'C': two+="1100"; break;
                case 'D': two+="1101"; break;
                case 'E': two+="1110"; break;
                case 'F': two+="1111"; break;
            }
        }
        
        int buling = 0;
        if(two.size()%3!=0)
            buling = 3-(two.size()%3);
        
        string budeling;
        for(int i=0;i<buling;i++)
            budeling += "0";
        two = budeling+two;
        
        int weishu = (int)(two.size()/3);
        
        string eight = "";
        
        for(int i=0;i<weishu;i++){
            string sub = two.substr(3*i,3);
            if(sub == "000")    eight += "0";
            else if(sub == "001")    eight += "1";
            else if(sub == "010")    eight += "2";
            else if(sub == "011")    eight += "3";
            else if(sub == "100")    eight += "4";
            else if(sub == "101")    eight += "5";
            else if(sub == "110")    eight += "6";
            else if(sub == "111")    eight += "7";
        }
        
        while(eight[0] == '0'){
            eight.erase(0,1);
        }
        
        cout<<eight<<endl;
        
    }
    return 0;
}
