#include <iostream>
#include"auxiliary.h"
#include"sort.h"
int main()
{
    //generateFile("in.txt", 7*1024*512);
    //openFile("in.txt");

    sort("in.txt", "b.txt", "c.txt");
    
    std::cout << "Hello World!\n";
}
