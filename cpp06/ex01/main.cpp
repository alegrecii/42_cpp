#include "Serializer.hpp"

int main (void)
{
	Data*		data = new Data;
	uintptr_t	serialized;
	Data*		deserialized;

	data->test = "Ciaooooo";
	serialized = Serializer::serialize(data);
	deserialized = Serializer::deserialize(serialized);
	std::cout << "data->test: " << data->test << std::endl;
	std::cout << "deserialized->test: " << deserialized->test << std::endl;
	delete data;
	return (0);
}
