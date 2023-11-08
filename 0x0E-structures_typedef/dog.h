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

typedef struct dog dog;
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
