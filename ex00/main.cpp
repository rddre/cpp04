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
static void wrong_child()
{
	std::cout << "\n--- wrong child test ---" << std::endl;
	const Animal* wrong_father = new WrongCat();

	std::cout << wrong_father->getType() << std::endl;
	wrong_father->makeSound();
}*/
/*
static void wrong_cast_child()
{
	std::cout << "\n--- wrong cast child test ---" << std::endl;
	const Animal* wrong_father = (const Animal*) new WrongCat();

	std::cout << wrong_father->getType() << std::endl;
	wrong_father->makeSound();
}*/

int main()
{
	main_pdf();
	wrong_pdf_test();
	//wrong_child();        erreur a la compilation, on ne peut pas convertir un WrongCat* en Animal*
	//wrong_cast_child();   compilation ok, mais comportement indéfini
	return 0;
}
