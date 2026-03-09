#include <iostream>
using namespace std;

class Marks {
	private:
		int marks[3][4];

	public:
		void input() {

			for (int i = 0; i < 3; i++) {
				cout << "\nEnter marks for Student " << (i + 1) << " (4 subjects):\n";

				for (int j = 0; j < 4; j++) {
					cout << "Subject " << (j + 1) << ": ";
					cin >> marks[i][j];
				}
			}
		}

		void display() {
			cout << "\nMarks Table (3 x 4):";

			for (int i = 0; i < 3; i++) {

				cout << "\nStudent " << (i + 1) << ": ";

				for (int j = 0; j < 4; j++) {

					cout << marks[i][j] << " ";

				}
			}
		}

		void average(int i) {

			int sum = 0;

			for (int j = 0; j < 4; j++) {

				sum += marks[i][j];

			}

			float avg = sum / 4.0;
			cout << "\n\nAverage of Student " << (i + 1) << " = " << avg << endl;
		}
};

int main()
{
	Marks table1;

	table1.input();
	table1.display();
	table1.average(0);

	return 0;
}
