#include <iostream>
using namespace std;

class Rectangle {
	private:
		float length;
		float width;

	public:
		void set(float len, float wid) {
			length = len;
			width = wid;
		}

		float area() {
			return length * width;
		}

		float perimeter() {
			return (length * 2) + (2 * width);
		}

		void display() {
			cout << "Length: " << length
				<< "\nWidth: " << width
				<< "\nArea: " << area()
				<< "\nPerimeter: " << perimeter() << endl;
		}
};

int main()
{
	Rectangle rect1;

	rect1.set(3.0, 45.3);
	rect1.display();

	return 0;
}
