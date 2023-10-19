#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_Data
{
	const char*	test;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &original);
	Serializer& operator=(Serializer const &original);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
