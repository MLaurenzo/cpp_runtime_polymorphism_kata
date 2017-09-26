#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Wrapper {
public:
    template<typename T>
    Wrapper(T object) : m_internal(make_unique<InternalImpl<T>>(object)) {}

    void print() const {}

private:
    struct InternalInterface {
        virtual ~InternalInterface() = default;
    };
    template<typename T>
    struct InternalImpl : InternalInterface
    {
        InternalImpl(T object) : m_object(object) {}

    private:
        T m_object;
    };
    unique_ptr<InternalInterface> m_internal;
};

int main()
{
    vector<Wrapper> v;
    v.emplace_back(string("I am using string class."));

    for_each(v.begin(), v.end(),
             [](const Wrapper& e) { e.print(); }
    );
}