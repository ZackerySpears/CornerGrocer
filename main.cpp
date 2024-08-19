#include "ProduceItem.h"

using namespace std;

int main() {
    string fileName = "differentProdueItems.txt"; //Filename for the text file containing items
    ProduceItem grocer(fileName); //Creates an instance of the ProduceItem class

    grocer.run();//Run the main program

    return 0;
}