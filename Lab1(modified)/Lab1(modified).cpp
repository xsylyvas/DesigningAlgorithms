#include <iostream>
#include"auxiliary.h"
#include"sort.h"
int main()
{
    generateFile("t.txt", 7*1024*512);
    preliminarySorting("t.txt", "in.txt", 1048576);
    sort("in.txt", "b.txt", "c.txt", 1048576);
    std::cout << "Hello World!\n";
    return 0;
}