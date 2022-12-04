#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Engine {
	int engineNo;
	string company;
	double volume;
public:
	Engine() {
		engineNo = 0;
		company = "";
		volume = 0;
	}
	Engine(int engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}
#pragma region Setter
	void SetEngineNo(int engineNo) {
		this->engineNo = engineNo;
	}
	void SetCompany(string company) {
		this->company = company;
	}
	void SetVolume(double volume) {
		this->volume = volume;
	}
#pragma endregion

#pragma region Getter
	int GetEngineNo() {
		return engineNo;
	}
	string GetCompany() {
		return company;
	}
	double GetVolume() {
		return volume;
	}
#pragma endregion

	void Show() {
		cout << "Engine No:" << engineNo << endl;
		cout << "Company:" << company << endl;
		cout << "Volume:" << volume << endl;
	}
};
class Car {
	int id;
	string model;
	string vendor;
	bool hasSpoiler;
	Engine engine;
public:
	Car(int id, string model, string vendor,bool hasSpoiler ,int engineNo, string company, double volume ) {
		engine.SetEngineNo(engineNo);
		engine.SetCompany(company);
		engine.SetVolume(volume);
		this->id = id;
		this->model = model;
		this->vendor = vendor;
		this->hasSpoiler = hasSpoiler;
	}
	void Show() {
		cout << "Model:" << model << endl;
		cout << "Vendor:" << vendor << endl;
		cout << "Spoiler?:" << hasSpoiler << endl;
		engine.Show();
	}

	Car& operator=(Car& other) {
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		hasSpoiler = other.hasSpoiler;
		engine.SetEngineNo(other.engine.GetEngineNo());
		engine.SetCompany(other.engine.GetCompany());
		engine.SetVolume(other.engine.GetVolume());
		return*this;
	}

	friend ostream& operator<<(ostream& out, Car& other) {
		cout << "Id" << other.id << endl;
		cout << "Model:" << other.model << endl;
		cout << "Vendor:" << other.vendor << endl;
		other.engine.Show();
		return out;
	}
};


class Ship {
	int id;
	string model;
	string vendor;
	bool hasSail;
	Engine engine;

public:
	Ship(int id, string model, string vendor, int engineNo, string company, double volume, bool hasSail) {
		this->id = id;
		this->model = model;
		this->vendor = vendor;
		this->hasSail = hasSail;
		engine.SetEngineNo(engineNo);
		engine.SetVolume(volume);
		engine.SetCompany(company);
	}

	void Show() {
		cout << "Id:" << id << endl;
		cout << "Model:" << model << endl;
		cout << "Vendor:" << vendor << endl;
		cout << "Has it sail?:" << hasSail << endl;
		engine.Show();
	}

	Ship& operator=(Ship& other) {
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		hasSail = other.hasSail;
		engine.SetEngineNo(other.engine.GetEngineNo());
		engine.SetCompany(other.engine.GetCompany());
		engine.SetVolume(other.engine.GetVolume());
		return*this;
	}

	friend ostream& operator<<(ostream& out, Ship& other) {
		cout << "Id:" << other.id << endl;
		cout << "Model:" << other.model << endl;
		cout << "Sail ? :" << other.hasSail << endl;
		other.engine.Show();
		return out;
	}
};

class Airplane {
	int id;
	string model;
	string vendor;
	int engineCount;
	int passengerCapacity;
	Engine engine;

public:
	Airplane(int id, string model, string vendor, int engineNo, string company, double volume, int passengerCapacity, int engineCount) {
		engine.SetEngineNo(engineNo);
		engine.SetCompany(company);
		engine.SetVolume(volume);
		this->id = id;
		this->model = model;
		this->vendor = vendor;
		this->passengerCapacity = passengerCapacity;
		this->engineCount = engineCount;
	}
	void Show() {
		cout << "Id:" << id << endl;
		cout << "Model:" << model << endl;
		cout << "Vendor:" << vendor << endl;
		cout << "Passenger capacity:" << passengerCapacity << endl;
		cout << "Engine count:" << engineCount << endl;
		engine.Show();
	}

	Airplane& operator=(Airplane& other) {
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		passengerCapacity = other.passengerCapacity;
		engineCount = other.engineCount;
		engine.SetEngineNo(other.engine.GetEngineNo());
		engine.SetCompany(other.engine.GetCompany());
		engine.SetVolume(other.engine.GetVolume());
		return*this;
	}

	friend ostream& operator<<(ostream& out, Airplane& other) {
		cout << "Id:" << other.id << endl;
		cout << "Model:" << other.model << endl;
		cout << "Vendor:" << other.vendor << endl;
		cout << "Passenger Capacity:" << other.passengerCapacity << endl;
		cout << "Engine Count:" << other.engineCount << endl;
		other.engine.Show();
		return out;
	}
};

template<class T>
class Stack {
	T* arr;
	int capacity;
	int top;
public:
	Stack(int size) {
		capacity = size;
		arr = new T[capacity];
		top = -1;
	}
	
	bool IsFull() { return capacity - 1 == top; }
	bool IsEmpty() { return top == -1; }

	void Push(T value) {
		assert(!IsFull() && "Stack overflow");
		arr[++top] = value;
	}

	void Pop() {
		assert(!IsEmpty() && "Stack is empty");
		top--;
	}

	T Top(){ 
		assert(!IsEmpty() && "Stack is empty");
		return arr[top];
	}

	~Stack() { delete[] arr; }
};

class VehicleDepo {
public:
	stack<Car>cars;
	stack<Airplane>airplanes;
	stack<Ship>ships;

	void ShowAllVehicle() {
		while (!cars.empty()) {
			cout << cars.top() << endl;
			cars.pop();
		}
		while (!airplanes.empty()) {
			cout << airplanes.top() << endl;
			airplanes.pop();
		}
		while (!ships.empty()) {
			cout << ships.top() << endl;
			ships.pop();
		}
	}
};

int main() {
	Car mercedes(1,"maybach", "mercedes", 0, 2, "mercedes", 3.5 );
	Airplane douglas(2, "douglas", "dc-3", 2, "douglas", 567, 1, 1);
	Ship seaBatical(3, "seabatical", "bati", 3, "batisea", 3535, 2);
	VehicleDepo depo;
	depo.cars.push(mercedes);
	depo.airplanes.push(douglas);
	depo.ships.push(seaBatical);
	depo.ShowAllVehicle();

}




























