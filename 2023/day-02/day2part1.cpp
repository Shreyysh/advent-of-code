//elf takes out cubes THEN PUTS IT BACK AGAIN
//Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the IDs of those games?

#include <iostream>
#include <fstream> //for reading txt files
#include <sstream> //to split string
#include <vector>

using namespace std;

vector<string> words_in_line(vector<string> words, string line);
bool colored_cubes(vector<string> words, bool isValid);

int main(void) 
{
    ifstream fi;
    fi.open("input-d2.txt");

    int id = 0, result = 0;
    bool isValid;
    string line;
    vector<string> words;

    while (getline(fi, line)) {
        words.clear();

        id += 1;

        words = words_in_line(words, line);
        isValid = colored_cubes(words, isValid);
        
        if (isValid) result += id;
        else continue;
        
    }

    cout << "Answer is: " << result << endl;
}

vector<string> words_in_line(vector<string> words, string line) 
{
    string part;
    istringstream iss(line);
    while (iss>>part) words.push_back(part);

    return words;
}

bool colored_cubes(vector<string> words, bool isValid) 
{
    for (auto it = words.begin(); it != words.end(); it++) {
        if (*(it) == "red" || *(it) == "red," || *(it) == "red;") {
            if (stoi(*(it-1)) > 12) {
                isValid = false;
                break;
            }
            else isValid = true;
        } else if (*(it) == "green" || *(it) == "green," || *(it) == "green;") {
            if (stoi(*(it-1)) > 13) {
                isValid = false;
                break;
            }
            else isValid = true;
        } else if (*(it) == "blue" || *(it) == "blue," || *(it) == "blue;") {
            if (stoi(*(it-1)) > 14) {
                isValid = false;
                break;
            }
            else isValid = true;
        }
    }

    return isValid;
}