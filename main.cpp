#include "BigO.h"
#include <iostream>

int helping(){
    int selection;

    std::cout << "\n\n\t###### BigO plot maker #######" << std::endl;

    std::cout << "1- O(1)\n2- O(n)\n3- O(Log N)\n4- O(N Log N)\n5- O(N^2)\n6- O(2^n)\n7- O(n!)";
    std::cout << "\n\n\tChoose an option(type '-1' to exit): ";
    std::cin >> selection;

    return selection;
}

int main() {
    BigO o;
    int selection = 1;
    while(selection){
        switch (helping())
        {
        case 1:
            o.o1();
            break;
        case 2:
            o.oN();
            break;
        case 3:
            o.oLogN();
            break;
        case 4:
            o.oNLogN();
            break;
        case 5:
            o.oN2();
            break;
        case 6:
            o.o2N();
            break;
        case 7:
            o.oNFact();
            break;      
        case -1:
            selection = 0;
            break;
        }
    }
    return 0;
}
