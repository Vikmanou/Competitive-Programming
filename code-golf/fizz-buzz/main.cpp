#include <iostream>
#include <string>
int main(){for(int i=1;i<101;i++){std::cout<<(!(i%3)?!(i%5)?"FizzBuzz":"Fizz":!(i%5)?"Buzz":std::to_string(i))<<'\n';}}