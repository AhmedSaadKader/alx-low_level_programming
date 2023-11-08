#ifndef DOG_H
#define DOG_H
/**
 * struct dog - describes dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */

struct dog
{
	char *name;   /* Name of the dog */
	float age;    /* Age of the dog */
	char *owner;  /* Owner of the dog */
};

void init_dog(struct dog *d, char *name, float age, char *owner);
typedef struct dog dog;

#endif
