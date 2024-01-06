#include <iostream>
#include <string>
#include <vector>
#define g break
#define d case
typedef int z;z main(z c,char*a[]){for(z i=1;i<c;++i){std::string p=a[i];std::vector<z>w(32,0),n;for(z i=0,v=0;i<size(p);++i)switch(p[i]){d '>':++v;g;d '<':--v;g;d '+':++w[v];g;d '-':--w[v];g;d '.':std::cout<<char(w[v]);g;d '[':if(!w[v]){for(z j=i+1,b=0;j<size(p);++j){if(p[j]=='[')++b;else if(p[j]==']')if(!b){i=j;g;}else--b;}}else n.push_back(i);g;d ']':if(!w[v])n.pop_back();else i=n.back();}}}