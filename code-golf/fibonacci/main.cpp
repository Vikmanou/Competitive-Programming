#include <iostream>
int f(int n){if(n<2)return n;return f(n-1)+f(n-2);}
int main(){for(int i=0;i<31;++i)std::cout<<f(i)<<'\n';}