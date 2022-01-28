#include <iostream>

class Dog;

class Cat;

class Animal {
public:
    virtual void meetVoice(Animal *animal) = 0;

    virtual void meetVoice(Cat *animal) = 0;

    virtual void meetVoice(Dog *animal) = 0;

    static void meeting(Animal *, Animal *);
};

class Dog : public Animal {
public:
    virtual void meetVoice(Animal *animal) override {
        animal->meetVoice(this);
    }

    virtual void meetVoice(Cat *animal) override {
        std::cout << "Meow Bark" << std::endl;
    }

    virtual void meetVoice(Dog *animal) override {
        std::cout << "Woof-Woof" << std::endl;
    }
};

class Cat : public Animal {
public:
    virtual void meetVoice(Animal *animal) override {
        animal->meetVoice(this);
    }

    virtual void meetVoice(Dog *animal) override {
        std::cout << "Bark Meow" << std::endl;
    }

    virtual void meetVoice(Cat *animal) override {
        std::cout << "Purr Purr" << std::endl;
    }
};

void Animal::meeting(Animal *a, Animal *b) {
    a->meetVoice(b);
}

int main() {
    Animal *a = new Dog();
    Animal *b = new Cat();
    Animal::meeting(a, a);
    Animal::meeting(a, b);
    Animal::meeting(b, a);
    Animal::meeting(b, b);

    return 0;
}