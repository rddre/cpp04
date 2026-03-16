#ifndef DOG_HPP
#define DOG_HPP

#include "../animal/animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		virtual void makeSound() const;
};

#endif
