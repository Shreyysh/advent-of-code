/*
The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int main(void) 
{
    ifstream fi;
    string line;

    fi.open("input-d1.txt", ios::in);

    if (!fi) cout << "error" << endl;

    fi.seekg(0, ios::beg);

    int sum = 0;

    while (getline(fi, line)) {
        
        string digits, doubledigits;
        
        for (const char c : line) {
            if (isdigit(c)) {
                digits += c;
            }
        }

        doubledigits += digits[0];
        doubledigits += digits.back();

        sum += stoi(doubledigits);
    }

    cout << "calibaration value: " << sum << endl;
}