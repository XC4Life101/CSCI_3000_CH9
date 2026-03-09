#include <iostream>
using namespace std;

class Battery {
	private:
		int bat_lvl;

	public:
		Battery() {
			bat_lvl = 50;
		}

		void charge(int val) {
			if (val > 0) {
				bat_lvl += val;
				if (bat_lvl > 100) {
					bat_lvl = 100;
				}
			}
		}

		void use(int min) {
			if (min > 0) {
				bat_lvl -= min;
				if (bat_lvl < 0) {
					bat_lvl = 0;
				}
			}
		}

		void display() {
			cout << "Battery Level: " << bat_lvl << "%" << endl;
		}
};

int main()
{
	Battery phone;

	phone.display();
	phone.use(45);
	phone.display();
	phone.charge(77);
	phone.display();

	return 0;
}
