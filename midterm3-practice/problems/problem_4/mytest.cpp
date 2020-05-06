#include <iostream>
#include <string>
#include "problem_classes.cpp"

void test1() {
    std::cout << "Creating Appliance with name \"Sears Daub 9\"" << std::endl;
    Appliance *d0 = new Appliance("Sears Daub 9");
    std::cout << d0->getName() << " exists." << std::endl;
    std::cout << std::endl;
}

void test2() {
    std::cout << "Creating Dishwasher with name \"Sears Dishwasher Master\"" << std::endl;
    Dishwasher d1("Sears Dishwasher Master");
    std::cout << "Adding 15 dishes to the dishwasher..." << std::endl;
    d1.loadDishes(15);
    std::cout << d1.getName() << ": powerUsed=" << d1.getEnergyUsed() << std::endl;

    std::cout << std::endl;

    std::cout << "Creating Dishwasher with name \"Sears Dishwasher Extreme\"" << std::endl;
    Dishwasher d2("Sears Dishwasher Extreme");
    std::cout << "Adding 30 dishes to the dishwasher..." << std::endl;
    d2.loadDishes(30);
    std::cout << d2.getName() << ": powerUsed=" << d2.getEnergyUsed() << std::endl;

    std::cout << std::endl;
}

void test3() {
    std::cout << "Creating Washer with name \"Sears Washer Master\"" << std::endl;
    Washer d3("Sears Washer Master");
    std::cout << "Adding 20 clothes to the washer..." << std::endl;
    d3.loadClothes(20);
    std::cout << d3.getName() << ": powerUsed=" << d3.getEnergyUsed() << std::endl;

    std::cout << std::endl;

    std::cout << "Creating Washer with name \"Sears Washer Extreme\"" << std::endl;
    Washer d4("Sears Washer Extreme");
    std::cout << "Adding 40 clothes to the washer..." << std::endl;
    d4.loadClothes(40);
    std::cout << d4.getName() << ": powerUsed=" << d4.getEnergyUsed() << std::endl;

    std::cout << std::endl;
}

void test4() {
    std::cout << "Creating Microwave with name \"Sears Microwave Master\"" << std::endl;
    Microwave d5("Sears Microwave Master");
    std::cout << "Adding 50 food to the microwave..." << std::endl;
    d5.addFood(50);
    std::cout << d5.getName() << ": powerUsed=" << d5.getEnergyUsed() << std::endl;

    std::cout << std::endl;

    std::cout << "Creating Microwave with name \"Sears Microwave Extreme\"" << std::endl;
    Microwave d6("Sears Microwave Extreme");
    std::cout << "Adding 100 food to the microwave..." << std::endl;
    d6.addFood(100);
    std::cout << d6.getName() << ": powerUsed=" << d6.getEnergyUsed() << std::endl;

    std::cout << std::endl;
}

void test5() {
    // Checks polymorphism
    Appliance ** appliances = new Appliance*[3];
    Dishwasher * d7;
    Washer * d8;
    Microwave * d9;
    std::cout << "Creating Dishwasher with name \"Sears Dishwasher Master\"" << std::endl;
    appliances[0] = new Dishwasher("Sears Dishwasher Master");
    std::cout << "Adding 15 dishes to the dishwasher..." << std::endl;
    d7 = (Dishwasher *)appliances[0];
    d7->loadDishes(15);
    std::cout << "Creating Washer with name \"Sears Washer Master\"" << std::endl;
    appliances[1] = new Washer("Sears Washer Master");
    std::cout << "Adding 20 clothes to the washer..." << std::endl;
    d8 = (Washer *)appliances[1];
    d8->loadClothes(20);
    std::cout << "Creating Microwave with name \"Sears Microwave Master\"" << std::endl;
    appliances[2] = new Microwave("Sears Microwave Master");
    std::cout << "Adding 50 food to the microwave..." << std::endl;
    d9 = (Microwave *) appliances[2];
    d9->addFood(50);

    std::cout << std::endl;

    std::cout << "Finding the energy used by each appliance..." << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << appliances[i]->getName() << ": powerUsed=" << appliances[i]->getEnergyUsed() << std::endl;
    }
    std::cout << std::endl;
}

int main( int argc, char ** argv ) {
    if ( argc < 2 ) {
    std::cout << "Usage: test_array test1|test2|test3|test4|test5|test6" << std::endl;
    exit(1);
    }

    std::string test = argv[1];

    std::cout << "Running " << test << std::endl;

    if ( test == "test1" ) {
    test1();
    }
    else if ( test == "test2" ) {
    test2();
    }
    else if ( test == "test3" ) {
    test3();
    }
    else if ( test == "test4" ) {
    test4();
    }
    else if ( test == "test5" ) {
    test5();
    }
    else {
    std::cout << "Test not Found!" << std::endl;
    exit(1);
    }
}