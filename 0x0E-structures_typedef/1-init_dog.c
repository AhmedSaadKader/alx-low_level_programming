#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initialize a variable of type struct dog
 * @d: dog structure
 * @name: array of name of dog
 * @age: age of dog
 * @owner: owner of dog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	dog *dog_d;

	dog_d = malloc(sizeof(dog));
	if (dog_d == NULL)
		return (NULL);
	dog_d->name = name;
	dog_d->age = age;
	dog_d->owner = owner;

	return (dog_d);
}
