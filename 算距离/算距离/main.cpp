#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

float s2i(string str){
    stringstream ss;
    float x;
    ss << str;
    ss >> x;
    return x;
}

float gamex[11]={74,59,58,34,34,38,57,52,50,46,9};
float gamey[11]={81,65,40,78,57,24,12,76,32,47,44};
float distanceIndex=0;

int main()
{
    for(int i=0;i<11;i++){
        for (int j=0; j<11 && j!=i; j++) {
            distanceIndex+=sqrt((gamex[i]-gamex[j])*(gamex[i]-gamex[j])+(gamey[i]-gamey[j])*(gamey[i]-gamey[j]));
        }
        
    }
    distanceIndex /=2;
    cout<<distanceIndex<<endl;
    return 0;
}

