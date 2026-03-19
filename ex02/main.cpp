#include "all.hpp"

//                ancien test qui marche toujouts du ex00
static void test_ex00()
{
	std::cout << "\n--- Subject main test ---" << std::endl;
	// const Animal* meta = new Animal();// ce test la ner marche plus 
										// 	car on ne peut pas instancier une classe abstraite
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	//meta->makeSound();

	delete i;
	delete j;
	//delete meta;
}

static void test_ex00_wrong()
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

// 			  test qui marche toujours du ex01
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


//                test pertinant a cet exercice
/*
void test_animal_solo() // ca va pas marcher car c'est une classe abstraite
{
	Animal* a;
	a->makeSound();
	return ;
}*/

void test_animal_sous_classe() // ca par contre ca marche, car c'est une classe concrète qui hérite de la classe abstraite
{
	Animal* a = new Dog();
	a->makeSound();
	delete a;
}

int main()
{
	std::cout << "\n--- test classe abstraite ---" << std::endl;
	/* test de la classe abstraite */
	//test_animal_solo(); // faut retirer le commentaire pour tester,
						  //mais ça va pas marcher car c'est une classe abstraite

	/* test de la classe concrète */
	test_animal_sous_classe();

	std::cout << "\n\n\n--- old test who still works from ex00 ---" << std::endl;
	test_ex00();
	test_ex00_wrong();
	std::cout << "\n--- old test who still works from ex01 ---" << std::endl;
	test_deep_copy_dog();
	test_deep_copy_cat();

	return 0;
}
