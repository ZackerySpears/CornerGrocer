#ifndef PRODUCE_ITEM_H
#define PRODUCE_ITEM_H

#include <string>
using namespace std;

class ProduceItem {
    public:
        //Constructor that sets  the filename
        ProduceItem(const string file);

        //Display the frequency of a specific item
        void displayItemFrequency();

        //Placeholder method for displaying all items and their frequencies 
        void displayAllItemsAndFrequencies();

        //Placeholder method for displaying a histogram of all items
        void displayHistogram();

        //To run the loop
        void run();
    private:
        string fileName;

        //Method to cout the frequency of a specific word in the file
        int countWordFrequency(const string& word);
        
};

#endif