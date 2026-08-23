#pragma once

#include <string>

namespace pe {

inline bool isPalindrome(std::string s) {
    return s == std::string(s.rbegin(), s.rend());
}

}  // namespace pe
