#include <iostream>
#include <memory>

int x;

const int &getX() {
    return x;
}

class Foo {
public:
    Foo() {
        std::cout << "Ctor" << std::endl;
    }

    void bar() {
        std::cout << "bar" << std::endl;
    }

    ~Foo() {
        std::cout << "Dtor" << std::endl;
    }

};
//
//auto source() -> std::unique_ptr<Foo> {
//    return std::make_unique<Foo>();
//}
//
//auto sink(std::unique_ptr<Foo> ptr) {
//    ptr->bar();
//    return ptr;
//}

int main() {


    std::shared_ptr<Foo> fooptr = std::make_shared<Foo>();
    std::cout << fooptr.use_count() << std::endl;

    std::shared_ptr<Foo> otherptr = fooptr;
    std::cout << fooptr.use_count() << std::endl;

    std::weak_ptr<Foo> weaky = fooptr;
    std::shared_ptr<Foo> forth = weaky.lock();
    //forth.reset();
    std::cout << fooptr.use_count() << std::endl;
    {
        std::shared_ptr<Foo> third = fooptr;
        std::cout << fooptr.use_count() << std::endl;
    }

    std::cout << fooptr.use_count() << std::endl;

//    std::unique_ptr<Foo> otherPTR = source();
//
//    sink(std::move(otherPTR));
//    std::cout << "Fertig" << std::endl;
    return 0;
}
