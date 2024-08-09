//Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the IDs of those games?

#include <iostream>
#include <fstream> //for reading txt files
#include <sstream> //to split string
#include <vector>

using namespace std;

vector<string> words_in_line(vector<string> words, string line);
void colored_cubes(vector<string> words, int* redSum, int* greenSum, int* blueSum);

int main(void) 
{
    ifstream fi;
    fi.open("test-cases.txt");

    int id = 0, redSum, greenSum, blueSum, result = 0;
    string line;
    vector<string> words;

    while (getline(fi, line)) {
        words.clear();

        id += 1;
        redSum = greenSum = blueSum = 0;

        words = words_in_line(words, line);
        colored_cubes(words, &redSum, &greenSum, &blueSum);
        
        if (redSum > 12 || greenSum > 13 || blueSum > 14) {
            continue;
        } else {
            result += id;
            cout << result << endl;
        }
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

void colored_cubes(vector<string> words, int* redSum, int* greenSum, int* blueSum) 
{
    for (auto it = words.begin(); it != words.end(); it++) {
        if (*(it) == "red" || *(it) == "red," || *(it) == "red;") {
            *redSum += stoi(*(it-1));
        } else if (*(it) == "green" || *(it) == "green," || *(it) == "green;") {
            *greenSum += stoi(*(it-1));
        } else if (*(it) == "blue" || *(it) == "blue," || *(it) == "blue;") {
            *blueSum += stoi(*(it-1));
        }
    }
}