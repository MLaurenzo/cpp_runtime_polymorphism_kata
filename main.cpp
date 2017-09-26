#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

void print(const string& s)
{
    cout << s << endl;
}

class Wrapper {
public:
    template<typename T>
    Wrapper(T object) : m_internal(make_unique<InternalImpl<T>>(object)) {}

    friend void print(const Wrapper& wrapper)
    { wrapper.m_internal->print_(); }

private:
    struct InternalInterface {
        virtual ~InternalInterface() = default;
        virtual void print_() const = 0;
    };
    template<typename T>
    struct InternalImpl : InternalInterface
    {
        InternalImpl(T object) : m_object(object) {}
        void print_() const override
        { print(m_object); }

    private:
        T m_object;
    };
    unique_ptr<InternalInterface> m_internal;
};

struct Person
{
    Person(const string& firstname, const string& lastname)
            : m_firstname(firstname)
            , m_lastname(lastname)
    {}
    string m_firstname;
    string m_lastname;
};

void print(const Person& p)
{
    cout << "Firstname: " << p.m_firstname << ", lastname: " << p.m_lastname << endl;
}

int main()
{
    vector<Wrapper> v;
    v.emplace_back(string("I am using string class."));
    v.emplace_back(Person("Laurent", "BERTHOLLE"));

    for_each(v.begin(), v.end(),
             [](const Wrapper& e) { print(e); }
    );
}