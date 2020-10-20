// Workshop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //to allow work with files
#include <string> //to allow string methods like getline()
#include <vector> //to allow use of vectors
#include <sstream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    string word;
    int count = 1;
    int numberOfWords(0);
    int numberOfSentences(0);
    string fileName;
    cout << "Please give the name of the txt file that you would like to open." << endl;
    cin >> fileName;
    ifstream myFile; //takes in a file input
    myFile.open(fileName); //opens file
    vector<string> wordList;
    if (myFile.is_open()) 
    {
        string line;
        while (getline(myFile, line)) 
        {
            numberOfSentences++;
            stringstream lineStream(line); //split the line into individual words
            while (getline(lineStream, line, ' '))
            {
                word = line;
                numberOfWords++;
                wordList.push_back(word);
            }
        }
        
    }
    else 
    {
        cout << "Cannot open file" << endl;
    }
    for (int i = 0; i < wordList.size(); i++) 
    {
        cout << wordList[i] << endl;
    }
    cout << "Number of sentences = " << numberOfSentences << " Number of Words =  " << numberOfWords << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
