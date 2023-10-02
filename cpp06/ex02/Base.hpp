#pragma once

#include <string>
#include <iostream>
#include <ctime>

//----------------------BASE----------------------

class Base
{
private:

public:
	virtual ~Base();
};
Base::~Base()
{
}

//----------------------AAAA---------------------

class A : public Base
{
private:
public:
	A();
};

A::A()
{
	std::cout << "A was created!" << std::endl;
}

//----------------------BBBB---------------------

class B : public Base
{
private:

public:
	B();
};

B::B()
{
	std::cout << "B was created!" << std::endl;
}

//----------------------CCCC---------------------

class C : public Base
{
private:

public:
	C();
};

C::C()
{
	std::cout << "C was created!" << std::endl;
}
