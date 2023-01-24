
#include <vector>

//API - application program interface - интерфейс взаимодействия
#include <iostream>

//a
// b c
// d

//пример
//class a
//{
//public:
//	a(int maxSpeed) : _maxSpeed(maxSpeed) {
//
//	}
//private:
//	int _maxSpeed;
//};
//
//class B : public a
//{
//public:
//	B(int maxSpeed):a(maxSpeed){}
//private:
//	int _maxSpeed;
//};




 class  IVehicle { //  I найменование вектора
public:
	
	virtual void printName() {
		std::cout << "IVehicle" << std::endl;
	}
	
	virtual int getSpeed() = 0; // абстрактный метод, означает что нет определения и реализуется в наследнике

	virtual ~IVehicle() {    //virtual нужно добавить в деструктор родителя
		std::cout << "IVehicle destructor was called." << std::endl;
	}
};


class Car :public IVehicle {
public:
	Car(int speed) :  _speed(speed) {}
	~Car() {
		std::cout << "Car destructor was called." << std::endl;
	}
	void printName() override { //override пишем для перегрузки виртуаьлной функции
	std::cout << "Car" << std::endl;
	}
	 int getSpeed() override {
		  return _speed;
	 }
	
private:
	int _speed;
};


class Van : public Car {
public:
	Van(int speed) : Car(speed){}
	~Van() {
		std::cout << "Van destructor was called";
	}

private:
	int _speed;
};

class Motorcycle : public IVehicle {
public:
Motorcycle(int speed) : _speed(speed) {}
~Motorcycle() {
	std::cout << "Motorcycle destructor was called." << std::endl;
}

int getSpeed() override {
	return _speed;

}
private:
	int _speed;
};

void printer(IVehicle* vehicle) {
	vehicle->printName();
	std::cout << vehicle->getSpeed() << std::endl;
}




int main() {
	setlocale(LC_ALL, "Russian");
//	a A;
	//b B; // когда мы создаем объект из наследуемого класса, мы как бы внутри B создаем объект А
	//Когда мы делаем виртульаное наследование внутри объекта не создается другой объекта ( как в примеме выше, когда внутри B создается A)

	// наследование, имеется в виду этоот объект является подмножеством другого объекта

	//IVehicle* a = new IVehicle();
	IVehicle* b = new Car(50);

	IVehicle* c = new Motorcycle(60);

	IVehicle* d = new Van(70);


	std::vector<IVehicle*> vehicles; // вектор указателей на объекты класса
	//vehicles.push_back(a);
	vehicles.push_back(b);
	vehicles.push_back(c);
	vehicles.push_back(d);

	//-> тоже самое что == (*a).b() - обращение у указателю


	std::cout << "Traversing vehicles" << std::endl;
	//for (size_t i = 0; i < vehicles.size();i++) {
	//	vehicles[i]->printName(); //vehicles[0] == *a; a->printName();
	//}


	for (size_t i = 0; i < vehicles.size(); i++) {
		printer(vehicles[i]);
	}

	delete b;  // деструкторы вызываются в обратном порядке ( сначала дети, потом родители)
	delete c;
	delete d;




	return 0;
}