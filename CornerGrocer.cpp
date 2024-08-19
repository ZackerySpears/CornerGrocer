#include <iostream>
#include <stdexcept>
#include <fstream>
#include "ProduceItem.h"
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//ProduceItem: Initializes the ProduceItem object with the filename
ProduceItem::ProduceItem(const string file) : fileName(file) {}

//Counts the frequency of a specific word (item) in the file
int ProduceItem::countWordFrequency(const string& word) {
    ifstream file(fileName);//Open the file 
    if(!file.is_open()){ //Check if the file was opened successfully
        cout << "Error: Could not open the file." << endl;
        return -1; //Return -1 if the file couldn't be opened
    }

    string currentWord;
    int count = 0;
      //Read each word from the file and compare it to the input word

    while(file >> currentWord){
        //Convert both the current word and the input word to lowercase for case-insensitive comparison
        transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        string lowerWord = word;
        transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

         //Increment the count if the current word matches the input word
        if (currentWord == lowerWord) {
            count++;
        }
    }

    file.close();//Close the file
    return count; 
}

//Prompts the user to enter an item and displays its frequency
void ProduceItem::displayItemFrequency() {
    string word;
    cout << "Enter the item you are searching for?" << endl;
    cin >> word;

    int frequency = countWordFrequency(word); //Get the frequency of the entered item

    if(frequency != -1){
        cout << "The item " << word << " appears " << frequency << " times in the file" << endl;
    }
}

//Displays a list of all items and their frequencies
void ProduceItem::displayAllItemsAndFrequencies() {
    ifstream file(fileName); //Open the file
    if(!file.is_open()){ //Check if the file was opened successfully
        cerr << "Error: Could not open the file." << endl;
        return; //Exit the method if the file couldn't be opened
    }

    map<string, int> itemFrequency; //Map to store items and their frequencies
    string currentWord;

     //Read each word from the file and update its frequency in the map
    while(file >> currentWord){
        //Convert the current word to lowercase for case-insensitive counting
        transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        itemFrequency[currentWord]++;
    }

    file.close(); //Close files

    //Display the items and their frequencies
    cout << "Item Frequencies:" << endl; //Get the frequency of the entered item
    for(const auto& item : itemFrequency) {
        cout << item.first << ": " << item.second << endl;
    }

}
//Displays a histogram of all items based on their frequencies
void ProduceItem::displayHistogram() {
    ifstream file(fileName); //Open file
    if (!file.is_open()) { //Check if the file opens
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    map<string, int> itemFrequency;//Map to store items and their frequencies
    string currentWord;

    while (file >> currentWord) {
        //Convert the current word to lowercase for case-insensitive counting
        transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        itemFrequency[currentWord]++;
    }

    file.close(); //Close file

    //Display the histogram
    cout << "Histogram:" << endl;
    for (const auto& item : itemFrequency) {
        cout << item.first << " "; //Print the item name
        //Print asterisks corresponding to the frequency of the item
        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

//Main program loop that presents the menu and handles user input
void ProduceItem::run() {
    bool programLoop = true;//Allows the while loop to continue until the user chooses to exit
    int userInput;

    while(programLoop) {
        //Menu Title
        cout << "================================================================================" << endl;
        cout << "Corner Grocer" << endl; 
        cout << "================================================================================" << endl;
        cout << "1. Display frequency for a specific item" << endl;
        cout << "2. Display a list of all items and their frequencies" << endl;
        cout << "3. Display histogram of all items" << endl;
        cout << "4. Exit Aplication" << endl;
        cout << "Please enter your selection as a number 1-4" << endl;
        //Menu Title


        cin.exceptions(ios_base::failbit); //Throw error if userInput is not a number
        try { //Try catch to make sure user input is correct

            cin >> userInput; //Ask for user Input 
            if(userInput < 1 || userInput > 4) { //Validates if users enters number between 1 and 4 
                throw runtime_error("Invalid Option!"); //Throws error if not
            }
        }
        catch (ios_base::failure& excpt) { //Prints out error message if users enter not a number
            cout << "Invalid Option" << endl;
            cout << "Please enter number between 1 and 4." << endl;
            cout << endl;
            cin.clear(); //Clears out the input 
            cin.ignore(100, '\n');
            continue; 
        }
        catch (runtime_error& excpt){ //Prints out error message if users enter the wrong number
            cout << excpt.what() << endl;
            cout << "Please enter number between 1 and 4." << endl;
            cout << endl;
            continue; 
        }

        switch(userInput){ //Checks the user selection from the menu option
            case 1:
                displayItemFrequency();
                break;
            case 2:
                displayAllItemsAndFrequencies();
                break;
            case 3:
                displayHistogram();
                break;
            case 4:
                programLoop = false;
                cout << "Exiting the application." << endl;
                break;
        }
    }
    
}