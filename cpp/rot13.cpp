#include <iostream>
#include <string>
#include <cctype>

std::string rot13(std::string source)
{
  std::string transformed;
  for (size_t i = 0; i < source.size(); ++i) {
    if (isalpha(source[i])) {
      if ((tolower(source[i]) - 'a') < 13)
        transformed.append(1, source[i] + 13);
      else
        transformed.append(1, source[i] - 13);
    } else {
      transformed.append(1, source[i]);
    }
  }
  return transformed;
}

int main() {
    std::string teststring = "hello world {}";
    std::string output = rot13(teststring);
    std::cout << "rot13 of \"" << teststring << " is " << output << std::endl;
}
