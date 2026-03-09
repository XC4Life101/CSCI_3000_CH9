#include <iostream>
#include <string>
using namespace std;

class Student {

	private:
		string name;
		int marks;

	public:
		void set(string n, int m) {
			name = n;

			if (m >= 0 && m <= 100) {
				marks = m;
			}
			else {
				marks = 0;
			}
		}

		bool pass() {
			return marks >= 40;
		}

		void diplay() {
			cout << "Student Name: " << name << endl;
			cout << "Marks: " << marks << endl;
			cout << "Result: " << (pass() ? "Pass" : "Fail") << endl;
		}
};

int main()
{
	Student stu1;

	stu1.set("Jimbo", 68);
	stu1.diplay();

	return 0;

}