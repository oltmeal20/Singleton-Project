#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


// Datastore as a Singleton
// PRIVATE constructor
// PUBLIC method that RETURNS pointer to the object.
class DataStore {

private:
    static DataStore* instance;
    string data;

    // Private constructor so that no objects can be created.
    DataStore() {
        data = "0";
    }

public:
    static DataStore *getInstance () {
        if (!instance) {
            instance = new DataStore;
        }
        return instance;
    }

    string getData() {
        ifstream example_file;
        example_file.open(data);
        //cout << "\nContents of file " << filename << ":\n\n";
        if (example_file.is_open()) {
            string line;
            while (getline(example_file, line)) {
                cout << line << endl;
            }
            example_file.close();
            cout << "" << endl << endl;
        }
        else {
            cerr << "Unable to open INPUT file";
            cout << "" << endl << endl << endl;
        }
        return data;
    }

    void setData(string newData) {
        data = newData;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance()
// sort of sucks to have to do this, but in C++, we have to do it this way
DataStore* DataStore::instance = nullptr;

int main() {

    srand(time(NULL));
    string example_text_file_one = "./record_one.txt";
    string example_text_file_two = "./record_two.txt";
    //string example_text_file_three = "./record_three.txt";
    //string example_text_file_four = "./record_four.txt";

    DataStore *f = f->getInstance();
    cout << "f->getInstance() " << endl << endl;

    cout << "f->getData():" << endl;
    f->getData();

    f->setData(example_text_file_one);
    cout << "f->setData(example_text_file_one)" << endl << endl;

    cout << "f->getData():" << endl;
    f->getData();

    f->setData(example_text_file_two);
    cout << "f->setData(example_text_file_two)" << endl << endl;

    cout << "f->getData():" << endl;
    f->getData();

    return 0;
}