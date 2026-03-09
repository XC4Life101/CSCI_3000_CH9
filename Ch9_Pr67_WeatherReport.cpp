#include <iostream>
#include <string>
using namespace std;

class Report {
	private:
		float temp[7][2];

	public:
		void input() {

			for (int i = 0; i < 7; i++) {
				cout << "\nDay " << (i + 1) << " Morning temp: ";
				cin >> temp[i][0];

				cout << "      Evening temp: ";
				cin >> temp[i][1];
			}

		}

		void display() {

			cout << "Temperature (Morning / Evening):\n";

			for (int i = 0; i < 7; i++) {
				cout << "Day " << (i + 1) << ": " << temp[i][0] << ", " << temp[i][1] << endl;
			}

		}

		void hottest() {

			int hot;
			float max = (temp[0][0] + temp[0][1]) / 2.0;

			for (int i = 1; i < 7; i++) {
				float day = (temp[i][0] + temp[i][1]) / 2.0;

				if (day > max) {
					max = day;
					hot = i;
				}
			}

			cout << "\nHottest Day: Day " << (hot + 1) << " (Avg = " << max << ")" << endl;
		}
};

int main()
{
	Report weather;

	weather.input();
	weather.display();
	weather.hottest();

	return 0;
}