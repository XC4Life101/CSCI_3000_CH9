#include <iostream>
#include <string>
using namespace std;

class Item {
	private:
		string name;
		float price;
		int quantity;

	public:
		void set(string n, float p, int q) {
			name = n;
			if (p > 0) {
				price = p;
			}
			else {
				price = 0;
			}
			if (q > 0) {
				quantity = q;
			}
			else {
				quantity = 0;
			}
		}

		float cost() {
			return price * quantity;
		}

		void display() {
			cout << "Item Name: " << name
				<< "\nPrice: " << price
				<< "\nQuantity: " << quantity
				<< "\nTotal Cost: " << cost() << endl;
		}
};

int main()
{
	Item item1;

	item1.set("Milk", 2.5, 5);
	item1.display();

	return 0;
}