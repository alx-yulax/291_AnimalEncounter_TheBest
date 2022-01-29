#include <iostream>

class Dog;

class Cat;

class Animal {
public:
    virtual void meeting(Animal *) = 0;

    virtual void meeting(Dog *) = 0;

    virtual void meeting(Cat *) = 0;
};

class Dog : public Animal {
    void meeting(Animal *animal) override {
        animal->meeting(this);
    }

    void meeting(Dog *animal) override {
        std::cout << "Woof-Woof" << std::endl;
    }

    void meeting(Cat *animal) override {
        std::cout << "Meow Bark" << std::endl;
    }
};

class Cat : public Animal {
    void meeting(Animal *animal) override {
        animal->meeting(this);
    }

    void meeting(Dog *animal) override {
        std::cout << "Bark Meow" << std::endl;
    }

    void meeting(Cat *animal) override {
        std::cout << "Purr Purr" << std::endl;
    }
};

void meeting(Animal *a, Animal *b) {
    a->meeting(b);
}


int main() {
    Animal *a = new Dog;
    Animal *b = new Cat;

    meeting(a, a);
    meeting(a, b);
    meeting(b, a);
    meeting(b, b);
    return 0;
}
