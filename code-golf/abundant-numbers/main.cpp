#include <iostream>
int main(){for(int i=1;i<201;++i){int s=0,j=1;for(;j<i;++j)s+=!(i%j)*j;if(s>i)std::cout<<i<<'\n';}}