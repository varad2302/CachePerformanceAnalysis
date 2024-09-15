#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void parsec_roi_begin() 
{
}

void parsec_roi_end() 
{
}

struct Result {
    vector< vector<int> > A;
};

Result read(string filename) {
    vector< vector<int> > A;
    Result ab;
    string line;
    ifstream infile;
    infile.open (filename.c_str());

    int i = 0;
    while (getline(infile, line) && !line.empty()) {
        istringstream iss(line);
        A.resize(A.size() + 1);
        int a, j = 0;
        while (iss >> a) {
            A[i].push_back(a);
            j++;
        }
        i++;
    }
    infile.close();
    ab.A = A;
    return ab;
}

vector<int> gatherAlgo(const vector<vector<int>> DataStore) {
    int size = DataStore.size();
    srand(static_cast<unsigned int>(time(0)));
    
    vector<vector<int>> index(1000, vector<int>(2,0)); 
    vector<int> values(1000);
    
    // Generate 1,000 random indices
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j<2; j++)
        {
            index[i][j] = rand() % (size * size);
        } 
    }
    
    // Gather elements at the random indices
    for(int idx = 0; idx < 1000; idx++) 
    {
        int row = index[idx][0];  // Compute row
        int col = index[idx][1];  // Compute column
        values[idx] = DataStore[row][col];  // Gather the element
    }
    
    return values;  // Return the gathered data
}

// Updated to print a 1D vector
void printVector(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 != vec.size()) {
            cout << "\t";
        }
    }
    cout << endl;
}

int main (int argc, char* argv[]) {
    srand(time(0));
    string filename;
    if (argc < 3) {
        filename = "2000.in";
    } else {
        filename = argv[2];
    }
    Result result = read (filename);
    parsec_roi_begin();
    vector<int> C = gatherAlgo(result.A);  // Corrected to vector<int>
    parsec_roi_end();
    
    // Optionally print the gathered data as a 1D vector
    //printVector(C);
    
    return 0;
}