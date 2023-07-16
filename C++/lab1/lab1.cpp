#include <iostream>


using namespace std;


int main() {

    int number_1, number_2, number_3, temp_number;

    while (true){
        cout << "Enter the numbers: ";
        cin >> number_1;
        if (number_1 == 0){
            cout << "End of the program..." << endl;
            return 0;
        }
        cin >> number_2;
        if (number_2 == 0){
            cout << "End of the program..." << endl;
            return 0;
        }
        cin >> number_3;
        if (number_3 == 0){
            cout << "End of the program..." << endl;
            return 0;
        }

        // sorting numbers
        if (number_1 > number_2){
            temp_number = number_2;
            number_2 = number_1;
            number_1 = temp_number;
        }
        if (number_2 > number_3){
          	temp_number = number_3;
          	number_3 = number_2;
          	number_2 = temp_number;
        }
        if (number_1 > number_2){
          	temp_number = number_2;
          	number_2 = number_1;
          	number_1 = temp_number;
        }
        // end of sorting numbers

        cout << "Minimum number: " << number_1 << endl;
        cout << "Average number: " << number_2 << endl;
        cout << "Maximum number: " << number_3 << endl;

        cout << "________________________________" << endl << endl;
    }
    return 0;
}
