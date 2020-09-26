#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1,2,3};
    int *x = &v[0];
    //{1,2,3} -> {1,2,3,4,5,6,7}
    for(int i=4;i<8;i++)v.push_back(i);
    std::cout<<*x<<std::endl;
    return 0;
}