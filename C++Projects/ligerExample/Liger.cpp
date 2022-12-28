
#include <iostream>
using namespace std;

class Animal
{
public:
	double weight;
	// Virtual keyword enables polymorphism.
	void virtual setWeight(double weight)
	{
		this->weight = weight;
		cout << "Calling set weight in Animal" << weight << endl;
	}
	virtual double getWeight()
	{
		return weight;
	}
	// Virtual Destructors
	virtual ~Animal()
	{
		cout << "Destroying Animal" << endl;
	}
};

class Tiger : virtual public Animal
{
public:
	string name;
	// Overrides the setWeight inherited from Animal
	virtual void setWeight(double weight)
	{
		cout << "Calling set weight in Tiger" << endl;
		this->weight = weight * 2;
	}
	virtual void setName(string name)
	{
		this->name = name;
	}
	virtual string getName()
	{
		return name;
	}
	~Tiger()
	{
		cout << "Destroying Tiger" << endl;
	}
};

class Lion : virtual public Animal
{
public:
	string code;

	virtual void setCode(string code)
	{
		this->code = code;
	}
	virtual string getCode()
	{
		return code;
	}
	~Lion()
	{
		cout << "Destroying Lion" << endl;
	}
};

class Liger : public Tiger, public Lion
{
public:
	string description;

	void setDescription(string description)
	{
		this->description = description;
	}
	string getDescription()
	{
		return description;
	}
	~Liger()
	{
		cout << "Destroying Liger" << endl;
	}
};

int main()
{
	Animal *liger = new Liger;
	// Calls the setWeight of the Tiger
	// Tiger is the immediate parent and has a setWeight method that overrides
	// setWeight from Animal
	liger->setWeight(600);
	cout << "Liger Weight - " << liger->getWeight() << endl;

	delete liger;
}
