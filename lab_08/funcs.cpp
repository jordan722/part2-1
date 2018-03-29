#include <iostream>
#include <cctype>
#include <string>
#include <fstream> //ifstream include


using namespace std;

//task A
string removeLeadingSpaces(string line){
    
    for(int i = 0; i < line.length(); i++){
        if(isspace(line[i])){
            line.erase(line.begin()+i);
        } else {
            return line;
        }
    }

}

//task B
string countChar(string line, char c){
    int count = 0;
    bool openBlock = false;
    
    ifstream fin("tests.txt");
    
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }    
    
    while(fin >> line){
        for(int i = 0; i < fin.length(); i++){
            string line2 = removeLeadingSpaces(line);

            if(line2[i] == '{'){
                count++;
                openBlock = true;
            } else if(line2[i] == '}'){
                openBlock = false;
            }
            if(openBlock){
                line2.insert(0, "    ");
            }

            return line;
        }
    }

    fine.close();
}

