#include <iostream>
#include <string>

int main(void)
{
    using namespace std::string_literals;

    std::string output = "Hello World!"s;
    std::cout << output << std::endl;

    return 0;
}
