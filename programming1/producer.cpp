#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <pthread.h>

using namespace std;//original

int main() {//mutex full empty x item 1 item 2
    
    std::ifstream file("shared-memory.txt");
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
    }
    char ch;
    string fullmem;
    file.get(ch);
    while (!file.eof() && ch != ' ') {
        fullmem += ch;
        file.get(ch);
    }
    file.close();
    int mutex = (int)fullmem[0] - 49;//1
    int full = (int)fullmem[2] - 49;//0
    int empty = (int)fullmem[4] - 49;//2
    int x = (int)fullmem[6] - 49;//0
    
    if ((mutex == 1) && (empty != 0)) {
        std::ofstream file3("shared-memory.txt");
        if (!file3.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file3 << mutex +1<< "\n" << full +1<< "\n" << empty+1<< "\n" << x+1;
        file3.close();

        --mutex;
        std::ofstream file4("shared-memory.txt");
        if (!file4.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file4 << mutex + 1 << "\n" << full + 1 << "\n" << empty + 1 << "\n" << x + 1;
        file4.close();

        // Increase the number of full
        // slots by 1
        ++full;
        std::ofstream file5("shared-memory.txt");
        if (!file5.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file5 << mutex + 1 << "\n" << full + 1 << "\n" << empty + 1 << "\n" << x + 1;
        file5.close();
        // Decrease the number of empty
        // slots by 1
        --empty;
        std::ofstream file6("shared-memory.txt");
        if (!file6.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file6 << mutex + 1 << "\n" << full + 1 << "\n" << empty + 1 << "\n" << x + 1;
        file6.close();
        // Item produced
        x++;
        std::ofstream file7("shared-memory.txt");
        if (!file7.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file7 << mutex + 1 << "\n" << full + 1 << "\n" << empty + 1 << "\n" << x + 1;
        file7.close();
        printf("\nProducer produces \n"
            "item %d\n",
            x);

        // Increase mutex value by 1
        ++mutex;
        std::ofstream file8("shared-memory.txt");
        if (!file8.is_open()) {
            std::cout << "Unable to write file\n";
        }
        file8 << mutex + 1 << "\n" << full + 1 << "\n" << empty + 1 << "\n" << x + 1;
        file8.close();

    }
    else {
        cout << "table is full!\n";
    }
    // Decrease mutex value by 1
    
    
}