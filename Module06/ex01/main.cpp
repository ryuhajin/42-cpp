#include "Serializer.hpp"
#include <iostream>
#include <string>

int main(void)
{
    //data
    Data data = {"teemo", 100, 107.42f};

    std::cout << "[Data]" << std::endl;
    std::cout << "name: " << data._name << std::endl;
    std::cout << "age: " << data._age << std::endl;
    std::cout << "height: " << data._height << '\n' << std::endl;

    Data* data_ptr = &data;
    uintptr_t u_ptr = Serializer::serialize(data_ptr);
    std::cout << "uintptr_t: " << u_ptr << '\n' << std::endl;

    Data* deserialized_ptr = Serializer::deserialize(u_ptr);
    std::cout << "[Deserialized Data]" << std::endl;
    std::cout << "name: " << deserialized_ptr->_name << std::endl;
    std::cout << "age: " << deserialized_ptr->_age << std::endl;
    std::cout << "height: " << deserialized_ptr->_height << '\n' << std::endl;

    //test
    int i = 42;
	data_ptr = reinterpret_cast<Data*>(&i);

    std::cout << "[test]" << std::endl;
	std::cout << "Address of i: " << &i << std::endl;
	std::cout << "Address of data_ptr: " << data_ptr << std::endl;

	u_ptr = Serializer::serialize(data_ptr);
	std::cout << "uintptr_t: " << u_ptr << std::endl;

	deserialized_ptr = Serializer::deserialize(u_ptr);
	std::cout << "deserialized_ptr: " << deserialized_ptr << std::endl;

	int	*i_ptr = reinterpret_cast<int*>(deserialized_ptr);
	std::cout << "value of i_ptr: " << *i_ptr << std::endl;
    std::cout << "value of i: " << i << std::endl;

    return (0);
}
