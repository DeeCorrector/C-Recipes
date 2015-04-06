#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;
using namespace literals;

int main()
{
    using MyVector = vector<string>;


    auto copyStartTime = high_resolution_clock::now();

    MyVector copyConstructed;
    for (unsigned int i=0; i < 10000000; ++i)
    {
        string copyString{
	    "This is a pretty long string that"
            " must be copy constructed into"
	    " copyConstructed!"s };
        copyConstructed.push_back(copyString);    
    }

    auto copyEndTime = high_resolution_clock::now();

    auto moveStartTime = high_resolution_clock::now();

    MyVector moveConstructed;
    for (unsigned int i=0; i < 10000000; ++i)
    {
        moveConstructed.emplace_back(
	    "This is a pretty long string that"
            " must be move constructed into"
	    " moveConstructed!"s
	);
    }

    auto moveEndTime = high_resolution_clock::now();

    auto copyDuration =
	duration_cast<milliseconds>(copyEndTime - copyStartTime);
    cout << "Copy lasted: " << copyDuration.count() << "ms" << endl;

    auto moveDuration =
	duration_cast<milliseconds>(moveEndTime - moveStartTime);
    cout << "Move lasted: " << moveDuration.count() << "ms" << endl;
    
    return 0;
}
