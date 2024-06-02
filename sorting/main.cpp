#include <iostream>
#include <fstream> // To use ifstream
#include <vector>

using namespace std;


int main()
{
	vector<int> numbers;
	int i;

    ifstream inputFile("input.txt");        // Input file stream object


    if (inputFile.good())    // Check if file exists and then open it.
     {

        int current_number = 0;
        while (inputFile >> current_number)    // reads data from file stores the data in an array
        	numbers.push_back(current_number); //and stores them in a vector

        inputFile.close();  // Close the file.

        i=numbers.size();
        int Maximum, Minimum, l;

	/* Μεταβλητές Maximum και Minimum για ελάχιστη τιμή και μεταβλητή l (βοηθητική) για την αποθήκευση και την ανταλλαγή των τιμών Maximum και Minimum με την πρώτη και την τελευταία τιμή αντίστοιχα */
        for (int count = 0; count<i; count++) { //αναζήτηση για Maximum
            if (Maximum<numbers[count]) {Maximum=numbers[count]; l=count;} //αναθέτουμε στην l την τιμή Maximum
            }
            numbers[l]=numbers[i-1]; //Στην θέση της Maximum βάζουμε την τελευταία τιμή
            numbers[i-1]= Maximum; //Καταχώρηση της Maximum στο τελευταίο στοιχείο

        for (int count = 0; count<i; count++) {  //αναζήτηση για Minimum
            if (Minimum>numbers[count]) { Minimum=numbers[count]; l=count; } //αναθέτουμε στην l την τιμή Minimum
            }
            numbers[l]=numbers[0]; //Στην θέση της Minimum βάζουμε το πρώτο στοιχείο
            numbers[0]=Minimum;  //Καταχώρηση της Minimum στο πρώτο στοιχείο

        // Display the numbers read:
        cout << "The numbers are: ";
        for (int count = 0; count < i; count++){
            cout << numbers[count] << " ";
        }
        cout << endl;

    }else {
        cout << "Error in reading file!";
        exit(0);
    }


// stores the numbers in txt file using output file stram object
    ofstream outputfile;
    outputfile.open ("output.txt");
    for (int count = 0; count < i; count++){
    outputfile << numbers[count] << " ";
    }
    outputfile.close(); //close output file

    return 0;
}
