#include <iostream>

using namespace std;

struct MyStructCars{

    int ModelOfCar;

   union
   {
       struct
       {
           int hp1;
           int mileage1;
           double price1;
       } Mercedes;

       struct{
           int hp2;
           int mileage2;
           int numOfDoors;
       } BMW;

       struct{
           int hp3;
           int mileage3;
           double weight;
       } Audi;
   };
};

MyStructCars cars[50];
int sizeCar = 0;

// удалить автомобиль
void deleteCar(int index){
    if(index > sizeCar - 1 || index < 0){
        cout << "Enter data correctly!";
        return;
    }
    for (int i = index; i < sizeCar - 1; ++i) {
        cars[i] = cars[i+1];
    }
    sizeCar--;
}

// добавить авто
void addCar(MyStructCars car){
    cars[sizeCar] = car;
    sizeCar++;
}

// заполнение моделей авто
void fillInformationAboutCar(int length){
    sizeCar = length;
    for (int i = 0; i < sizeCar; ++i) {
        int model;
        cout << "Enter model: " << endl;
        cout << "1 - Mercedes" << endl;
        cout << "2 - BMW" << endl;
        cout << "3 - Audi" << endl;
        cin >> model;
        cars[i].ModelOfCar = model;
        if(model == 1){
            int hp;
            int mileage;
            double price;
            cout << "Enter hp: ";
            cin >> hp;
            cars[i].Mercedes.hp1 = hp;

            cout << "Enter mileage: ";
            cin >> mileage;
            cars[i].Mercedes.mileage1 = mileage;

            cout << "Enter price: ";
            cin >> price;
            cars[i].Mercedes.price1 = price;
        }
        else if(model == 2){
            int hp;
            int mileage;
            int numDoors;
            cout << "Enter hp: ";
            cin >> hp;
            cars[i].BMW.hp2 = hp;

            cout << "Enter mileage: ";
            cin >> mileage;
            cars[i].BMW.mileage2 = mileage;

            cout << "numDoors: ";
            cin >> numDoors;
            cars[i].BMW.numOfDoors = numDoors;
        }
        else{
            int hp;
            int mileage;
            int weight;
            cout << "Enter hp: ";
            cin >> hp;
            cars[i].Audi.hp3 = hp;

            cout << "Enter mileage: ";
            cin >> mileage;
            cars[i].Audi.mileage3 = mileage;

            cout << "Weight: ";
            cin >> weight;
            cars[i].Audi.weight = weight;
        }
    }
}

void writeToConsoleInformation(){
    for (int i = 0; i < sizeCar; ++i) {
        if(cars[i].ModelOfCar == 1){
            cout << "Model of car: Mercedes" << endl;
            cout << "hp: " << cars[i].Mercedes.hp1 << endl;
            cout << "mileage: " << cars[i].Mercedes.mileage1 << endl;
            cout << "price: " << cars[i].Mercedes.price1 << endl;
        }
        else if(cars[i].ModelOfCar == 2){
            cout << "Model of car: BMW" << endl;
            cout << "hp: " << cars[i].BMW.hp2 << endl;
            cout << "mileage: " << cars[i].BMW.mileage2 << endl;
            cout << "number of doors: " << cars[i].BMW.numOfDoors << endl;
        }
        else{
            cout << "Model of car: Audi" << endl;
            cout << "hp: " << cars[i].Audi.hp3 << endl;
            cout << "mileage: " << cars[i].Audi.mileage3 << endl;
            cout << "weight: " << cars[i].Audi.weight << endl;
        }
    }
}

int main() {

    MyStructCars car1{};
    car1.ModelOfCar = 1;
    car1.Mercedes.hp1 = 100;
    car1.Mercedes.mileage1 = 100000;
    car1.Mercedes.price1 = 30000000;

    MyStructCars car2{};
    car2.ModelOfCar = 2;
    car2.BMW.hp2 = 300;
    car2.BMW.mileage2 = 25000;
    car2.BMW.numOfDoors = 3;

    fillInformationAboutCar(3);
    cout << "======================================\n ";
    writeToConsoleInformation();

    addCar(car1);
    addCar(car2);
    cout << "======================================= \n";
    writeToConsoleInformation();

    deleteCar(0);
    cout << "======================================= ";
    writeToConsoleInformation();


    return 0;
}
