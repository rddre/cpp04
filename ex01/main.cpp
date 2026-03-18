#include "all.hpp"

void main_pdf()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;	
}

int main()
{
	std::cout << "===== TEST 1: polymorphic delete =====" << std::endl;
	main_pdf();
	std::cout << std::endl;
	
	std::cout << "===== TEST 2: deep copy Dog =====" << std::endl;
	Dog basicDog;
	basicDog.setIdea(0, "I want a bone");
	basicDog.setIdea(1, "I guard the house");

	Dog copiedDog(basicDog);
	basicDog.setIdea(0, "Changed idea in original dog");

	std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

	Dog assignedDog;
	assignedDog = basicDog;
	basicDog.setIdea(1, "Another change in original dog");

	std::cout << "basicDog idea[1]: " << basicDog.getIdea(1) << std::endl;
	std::cout << "assignedDog idea[1]: " << assignedDog.getIdea(1) << std::endl;
/*
	std::cout << std::endl;
	std::cout << "===== TEST 3: deep copy Cat =====" << std::endl;
	Cat basicCat;
	basicCat.setIdea(0, "I want fish");
	basicCat.setIdea(1, "I sleep all day");

	Cat copiedCat(basicCat);
	basicCat.setIdea(0, "Changed idea in original cat");

	std::cout << "basicCat idea[0]: " << basicCat.getIdea(0) << std::endl;
	std::cout << "copiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

	Cat assignedCat;
	assignedCat = basicCat;
	basicCat.setIdea(1, "Another change in original cat");

	std::cout << "basicCat idea[1]: " << basicCat.getIdea(1) << std::endl;
	std::cout << "assignedCat idea[1]: " << assignedCat.getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << "===== TEST 4: WrongAnimal behavior =====" << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << std::endl;
	wrong->makeSound();
	delete wrong;

	std::cout << std::endl;
	std::cout << "===== END =====" << std::endl;*/
	return 0;
}
