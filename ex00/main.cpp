#include "all.hpp"

static void main_pdf()
{
	std::cout << "\n--- Subject main test ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

static void wrong_pdf_test()
{
	std::cout << "\n--- Wrong polymorphism test ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCatAsWrongAnimal = new WrongCat();
	const WrongCat* realWrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongCatAsWrongAnimal->getType() << std::endl;
	wrongMeta->makeSound();
	wrongCatAsWrongAnimal->makeSound();
	realWrongCat->makeSound();

	delete realWrongCat;
	delete wrongCatAsWrongAnimal;
	delete wrongMeta;
}
/*
static void testCopyAndAssign()
{
	std::cout << "\n--- Copy/assignment test ---" << std::endl;
	Dog d1;
	Dog d2(d1);
	Cat c1;
	Cat c2;

	c2 = c1;
	d2.makeSound();
	c2.makeSound();
}*/

int main()
{
	main_pdf();
	wrong_pdf_test();
	//testCopyAndAssign();
	return 0;
}
