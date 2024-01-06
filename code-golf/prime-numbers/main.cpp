#include <iostream>
int main(){for(int i=2;i<101;++i){int p=1,j=2;for(;j<i;++j)if(!(i%j))p=0;if(p)std::cout<<i<<'\n';}}