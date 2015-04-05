#include <iostream>

using namespace std;

auto AutoFunctionFromReturn(int parameter)
{
    return parameter;
}

template <typename T>
auto AutoFunctionFromParameter(T parameter) -> decltype(parameter)
{
    return parameter;
}

template <typename T>
decltype(auto) AutoFunctionFromParameterCPP14(T parameter)
{
    return parameter;
}

int main()
{
    auto value = AutoFunctionFromReturn(1);
    cout << value << endl;

    value = AutoFunctionFromParameter(2);
    cout << value << endl;
 
    value = AutoFunctionFromParameterCPP14(3);
    cout << value << endl;

    return 0;
}
