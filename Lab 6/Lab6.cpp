/*
    Jakobe Lahr
    Computer Science FA_24
    Due: 12/3/24
    Lab 6: Lab 6 is a program that reads characters in binary 
    and transfers them to decimal numbers as long as they are
    valid without breaks or characters in the original 
    number.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inFile("BinaryIn.dat"); //open
    if (!inFile) {
        cout << "Error: Could not open file BinaryIn.dat\n";
        return 1;
    }

    //headings
    cout << left << setw(20) << "Binary Number" << "Decimal Equivalent\n";
    cout << "-----------------------------------------------\n";

    char ch;
    while (inFile.get(ch)) { //read characters 
        string originalN = "";  
        string binaryN = "";    
        bool isValid = true;         
        bool digitStarted = false;   
        bool breakD = false;  //for breaks

        //skip leading spaces or underscores
        while ((ch == ' ' || ch == '_') && inFile.get(ch)) {
            originalN += ch;
        }

        while (ch != '\n' && !inFile.eof()) {
            originalN += ch; 

            if (ch == '0' || ch == '1') { //correct binary digit
                if (breakD) { //for breaks
                    isValid = false;
                }
                binaryN += ch; 
                digitStarted = true;
            }
            else if (ch == ' ' || ch == '_') { 
                if (digitStarted) { //break within the number
                    breakD = true;
                }
            }
            else { //invalid
                isValid = false;
            }

            inFile.get(ch); 
        }

        //final
        cout << left << setw(20) << originalN;
        if (!isValid || binaryN.empty()) {
            cout << "Bad digit on input\n";
        }
        else {
            //convert
            int decimalValue = 0;
            for (char digit : binaryN) {
                decimalValue = decimalValue * 2 + (digit - '0');
            }
            cout << decimalValue << '\n';
        }
    }

    inFile.close();
    return 0;
}
