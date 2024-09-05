#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decodeIngredientString(const string& ingredientString, int repeatCount, string& decodedString) {
    decodedString = "";
    for (int i = 0; i < repeatCount; i++) {
        int j = 0;
        while (j < ingredientString.length()) {
            if (ingredientString[j] == '[') {
                int k = j + 1;
                while (isdigit(ingredientString[k])) {
                    k++;
                }
                int repeatCount = stoi(ingredientString.substr(j + 1, k - j - 1));
                string innerString = "";
                decodeIngredientString(ingredientString.substr(k + 1, ingredientString.length() - k - 2), repeatCount, innerString);
                decodedString += innerString;
                j = ingredientString.length();
            } else if (ingredientString[j] == '|') {
                decodedString += '/';
                j++;
            } else {
                decodedString += ingredientString[j];
                j++;
            }
        }
    }
}

void decodeIngredientsFromFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    if (inputFile.is_open() && outputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            int i = 0;
            while (i < line.length()) {
                if (isdigit(line[i])) {
                    int j = i + 1;
                    while (isdigit(line[j])) {
                        j++;
                    }
                    int repeatCount = stoi(line.substr(i, j - i));
                    string ingredientString = "";
                    int k = j + 1;
                    while (k < line.length() && line[k] != ']') {
                        ingredientString += line[k];
                        k++;
                    }
                    string decodedString;
                    decodeIngredientString(ingredientString, repeatCount, decodedString);
                    outputFile << decodedString;
                    i = k + 1;
                } else {
                    outputFile << line[i];
                    i++;
                }
            }
            outputFile << endl;
        }
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open input or output file." << endl;
    }
}

int main() {
    decodeIngredientsFromFile("Lab5_P2_MT_Step1_in.txt", "Lab5_P2_MT_Step1_out.txt");
    return 0;
}

