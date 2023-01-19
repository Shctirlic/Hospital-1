#include <iostream>
#include <map>
#include <string>


using namespace std;


class Hospital
{
private:

	map<int, string> patients;
	int k = 0;

public:

	void registration(int id, string name)
	{
		patients.insert({ id, name });
	}

	void write_out(int id, string name)
	{
		map<int, string>::iterator it = patients.find(id);
		patients.erase(it);

		cout << "patient  with id =" << id << "   and name = " << name << "  - write out; " << endl;
	}

	void procedures(int id, string name)
	{
		cout << "patient  with id =" << id << "   and name = " << name << "  - procedure performed; " << endl;
		write_out(id, name);
		k++;
	}

	int number_procedures_performed()
	{
		return k;
	}
};

int main()
{
	Hospital hospital;

	hospital.registration(1, "aa");
	hospital.registration(2, "bb");
	hospital.registration(3, "cc");

	hospital.procedures(1, "aa");
	hospital.procedures(3, "cc");

	hospital.write_out(2, "bb");

	cout << " number of procedures performed : " << hospital.number_procedures_performed() << endl;
}