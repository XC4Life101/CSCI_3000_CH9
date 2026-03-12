#include <iostream>
using namespace std;

enum SlotStatus {
    EMPTY,
    OCCUPIED,
    RESERVED
};

class Warehouse{
    private:
        int shelf[4][5];
        SlotStatus slots[4][5];
        int daily[7];
        int total;

    public:
        Warehouse() {
            total = 0;

            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 5; c++) {
                    shelf[r][c] = 0;
                    slots[r][c] = EMPTY;
                }
            }

            for (int d = 0; d < 7; d++) {
                daily[d] = 0;
            }
        }

        void shelf_map() {

            cout << "\nShelf Map (E=Empty, O=Occupied, R=Reserved)";

            for (int r = 0; r < 4; r++) {

                cout << "\n\tRow " << (r + 1) << ": ";

                for (int c = 0; c < 5; c++) {
                    if (slots[r][c] == EMPTY) {
                        cout << "E ";
                    }
                    else if (slots[r][c] == OCCUPIED) {
                        cout << "O ";
                    }
                    else{
                        cout << "R ";
                    }
                }
            }
            cout << endl;
        }

        void reserve(int row, int col) {
            cout << endl;
            
            if (row < 0 || row >= 4 || col < 0 || col >= 5) {
                cout << "Invalid slot position!";
                return;
            }
            
            if (slots[row][col] == EMPTY) {
                slots[row][col] = RESERVED;
                cout << "Slot reserved successfully!";
            }
            else{
                cout << "Cannot reserve. Slot is not empty.";
            }
            
            cout << endl;
            
        }
        
        void add(int row, int col, int units) {
            
            cout << endl;
            
            if (row < 0 || row >= 4 || col < 0 || col >= 5) {
                cout << "Invalid slot position!";
                return;
            }
            
            if (units <= 0) {
                cout << "Units must be greater than 0!";
                return;
            }
            
            if (slots[row][col] == OCCUPIED) {
                cout << "Cannot add stock. Slot already occupied.";
                return;
            }
            
            shelf[row][col] = units;
            slots[row][col] = OCCUPIED;
            total += units;
            
            cout << "Stock added successfully! Units added: " << units;
            
            cout << endl;
        }
        
        void ship(int row, int col, int units, int day) {
            
            cout << endl;
            
            if (row < 0 || row >= 4 || col < 0 || col >= 5) {
                cout << "Invalid slot position!" << endl;
            }
            
            if (day < 1 || day > 7) {
                cout << "Invalid day! Use 1 through 7.";
                return;
            }
            
            if (units <= 0) {
                cout << "Units must be greater than 0!";
                return;
            }
            
            if (slots[row][col] != OCCUPIED) {
                cout << "Cannot ship. Slot is not occupied!";
                return;
            }
            
            if (units > shelf[row][col]) {
                cout << "Not enough stock in this slot!";
                return;
            }
            
            shelf[row][col] -= units;
            total -= units;
            daily[day - 1] += units;
            
            cout << "Shipped successfully! Units shipped: " << units;
            
            if (shelf[row][col] == 0) {
                slots[row][col] = EMPTY;
            }
            
            cout << endl;
        }
        
        void report() {
            
            cout << "\nWeekly Shipping report:";
            
            int shipped = 0;
            
            for (int day = 0; day < 7; day++) {
                cout << "\n\tDay " << (day + 1) << " shipped: " << daily[day];
                shipped += daily[day];
            }
            
            cout << "\n\n\tTotal shipped in a week: " << shipped;
            cout << "\n\tTotal units currently in warehouse: " << total;
            
            cout << endl;
        }
    
        void best() {
            
            cout << endl;
            
            int best = 0;
            int max = daily[0];
            
            for (int day = 0; day < 7; day++) {
                if (daily[day] > max) {
                    max = daily[day];
                    best = day;
                }
            }
            
            cout << "Best shipping day: Day " << (best + 1)
            << "(shipped " << max << " units)\n";
        }
        
};

int main() {
    
    Warehouse ware;

    ware.shelf_map();
    ware.reserve(0, 2);
    
    ware.add(0, 2, 50);
    ware.add(1, 1, 30);
    ware.add(2, 4, 20);
    
    ware.ship(0, 2, 10, 1);
    ware.ship(1, 1, 15, 4);

    ware.shelf_map();
    ware.report();
    ware.best();
    
    cout << endl;
    
    return 0;
}
