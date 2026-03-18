#ifndef DOG_HPP
#define DOG_HPP

#include "../animal/animal.hpp"
#include "../brain/brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		virtual void makeSound() const;
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
