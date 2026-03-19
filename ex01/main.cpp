#include "all.hpp"

void main_pdf()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;	
}

void test_deep_copy_dog()
{
	Dog original;

	original.setIdea(0, "I love bones");

	Dog copy = original;

	std::cout << "Original idea: " << original.getIdea(0) << std::endl;

	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	// on modifie l'original
	original.setIdea(0, "I hate cats");

	std::cout << "\nAfter modification:\n";

	std::cout << "Original idea: " << original.getIdea(0) << std::endl;

	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;
}

void test_deep_copy_cat()
{
	Cat a;
	Cat b;

	a.setIdea(0, "AAA");

	b = a;

	a.setIdea(0, "BBB");

	std::cout << b.getIdea(0) << std::endl;
}

//         test classe wrong pour montrer que sans virtual, le comportement est différent
void test_wrong_animal()
{
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << std::endl;
	wrong->makeSound();
	delete wrong;
}

int main()
{
	std::cout << "--- TEST polymorphic delete ---" << std::endl;
	main_pdf();
	std::cout << std::endl;

	std::cout << "\n\n--- TEST deep copy with dog ---" << std::endl;
	test_deep_copy_dog();
	std::cout << "\n--- TEST deep copy with cat ---" << std::endl;
	test_deep_copy_cat();

	std::cout << "\n\n--- TEST wrong animal ---" << std::endl;
	test_wrong_animal();

	return 0;
}
