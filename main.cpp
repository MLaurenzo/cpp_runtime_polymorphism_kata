#include <iostream>
#include <vector>
#include <algorithm>

#include "Wrapper.h"

using namespace std;

int main()
{
    vector<Wrapper> v;

    for_each(v.begin(), v.end(),
             [](Wrapper e) { e.print(); }
    );
}