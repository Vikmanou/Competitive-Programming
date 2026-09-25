#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;

  std::string result = "";

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '.') {
      result += '0';
    } else if (str[i] == '-') {
      if (str[i + 1] == '.') {
        result += '1';
        i++;
      } else if (str[i + 1] == '-') {
        result += '2';
        i++;
      }
    }
  }
  
  std::cout << result << std::endl;
  
  return 0;
}