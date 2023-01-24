
#include <vector>

//API - application program interface - ��������� ��������������
#include <iostream>

//a
// b c
// d

//������
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




 class  IVehicle { //  I ������������ �������
public:
	
	virtual void printName() {
		std::cout << "IVehicle" << std::endl;
	}
	
	virtual int getSpeed() = 0; // ����������� �����, �������� ��� ��� ����������� � ����������� � ����������

	virtual ~IVehicle() {    //virtual ����� �������� � ���������� ��������
		std::cout << "IVehicle destructor was called." << std::endl;
	}
};


class Car :public IVehicle {
public:
	Car(int speed) :  _speed(speed) {}
	~Car() {
		std::cout << "Car destructor was called." << std::endl;
	}
	void printName() override { //override ����� ��� ���������� ����������� �������
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
	//b B; // ����� �� ������� ������ �� ������������ ������, �� ��� �� ������ B ������� ������ �
	//����� �� ������ ����������� ������������ ������ ������� �� ��������� ������ ������� ( ��� � ������� ����, ����� ������ B ��������� A)

	// ������������, ������� � ���� ����� ������ �������� ������������� ������� �������

	//IVehicle* a = new IVehicle();
	IVehicle* b = new Car(50);

	IVehicle* c = new Motorcycle(60);

	IVehicle* d = new Van(70);


	std::vector<IVehicle*> vehicles; // ������ ���������� �� ������� ������
	//vehicles.push_back(a);
	vehicles.push_back(b);
	vehicles.push_back(c);
	vehicles.push_back(d);

	//-> ���� ����� ��� == (*a).b() - ��������� � ���������


	std::cout << "Traversing vehicles" << std::endl;
	//for (size_t i = 0; i < vehicles.size();i++) {
	//	vehicles[i]->printName(); //vehicles[0] == *a; a->printName();
	//}


	for (size_t i = 0; i < vehicles.size(); i++) {
		printer(vehicles[i]);
	}

	delete b;  // ����������� ���������� � �������� ������� ( ������� ����, ����� ��������)
	delete c;
	delete d;




	return 0;
}