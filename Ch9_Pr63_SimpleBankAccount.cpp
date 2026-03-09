#include <iostream>
using namespace std;

class Account {
	private:
		float balance;

	public:
		Account() {
			balance = 0;
		}

		void deposit(float ammount){
			if (ammount > 0) {
				balance += ammount;
			}
		}

		void withdraw(float ammount) {
			if (ammount > 0 && ammount <= balance) {
				balance -= ammount;
			}
			else {
				cout << "Insufficient Balance!";
			}
		}

		void display() {
			cout << "Current Balance: " << balance << endl;
		}
};

int main()
{
	Account acc1;

	acc1.deposit(500);
	acc1.display();

	acc1.withdraw(200);
	acc1.display();

	acc1.withdraw(1000);

	return 0;
}
