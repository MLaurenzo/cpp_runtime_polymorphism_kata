# cpp_runtime_polymorphism_kata #

## Introduction ##
When you want to treat several classes with the same function but having different behaviour,
a common approach is to implement the polymorphism by creating a base class and making the other classes deriving from this one and implement its methods.

## Kata ##
The goal is this kata is to explore another way of having polymorphism without inheritance.

Your mission is to create a Wrapper class which will serve as storage for any class and will allow to call the print method on it.
```
int main()
{
    vector<Wrapper> v;
    v.emplace_back(string("I am using string class."));
    v.emplace_back(Person("Laurent", "BERTHOLLE"));

    for_each(v.begin(), v.end(),
             [](const Wrapper& e) { print(e); }
    );
}
```