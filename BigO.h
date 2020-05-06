#include "Algorithm/Algorithm.h"
#include "matplotlibcpp.h"

#include <iostream>
#include <vector>

namespace plt = matplotlibcpp;

class BigO{
    public:
        Algorithm algo;
        void oLogN();
        void o1();
        void oN();
        void oNLogN();
        void oN2();
        void o2N();
        void oNFact();
};

void BigO::oLogN(){
    std::cout << "\n\n\t---------O(Log(N))---------\n\n";

    algo.count = std::pow(10, 1);
    algo.max = std::pow(10, 4);

    int n = 10, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        BST<int> tree = algo.binary_tree();

        start = algo.current_time_nanoseconds();
        int minVal = tree.maxValue();
        end = algo.current_time_nanoseconds();
        
        total = std::abs(end - start);
        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count * 2;

        std::cout << "Count: " << algo.count << "\tTime: " << total << "\tAnswer: " << minVal << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for Log(n)");
    plt::legend();
    plt::save("./output/oLogN.png");
}

void BigO::o1(){
    std::cout << "\n\n\t---------O(1)---------\n\n";

    algo.count = std::pow(10, 1);
    algo.max = std::pow(10, 4);

    int n = 10, start, end, total;
    
    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        int arr[algo.count];
        for(int j = 0 ; j < algo.count ; j++){
            arr[j] = n;
        }
        start = algo.current_time_nanoseconds();
        int data = arr[(rand() % algo.count)];
        end = algo.current_time_nanoseconds();
        
        total = std::abs(end - start);
        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count * 2;

        std::cout << "Count: " << algo.count << "\tTime: " << total << "\tAnswer: " << data << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for O(1)");
    plt::legend();
    plt::save("./output/o1.png");
}

void BigO::oN(){
    std::cout << "\n\n\t---------O(N)---------\n\n";
    algo.count = std::pow(10, 1);
    algo.max = std::pow(10, 4);

    int n = 10, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        std::vector<int> arr = algo.arr_gen();

        start = this->algo.current_time_nanoseconds();
        auto value = std::find(arr.begin(), arr.end(), 15);
        end = this->algo.current_time_nanoseconds();

        total = std::abs(end - start);

        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count * 2;

        std::cout << "Count: " << algo.count << "\tTime:" << total << "\tAnswer: " << value - arr.begin() + 1 << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for N");
    plt::legend();
    plt::save("./output/oN.png");
}

void BigO::oNLogN(){
    std::cout << "\n\n\t---------O(NLogN)---------\n\n";
    this->algo.count = std::pow(10, 1);
    this->algo.max = std::pow(10, 4);

    int n = 10, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; i++) {
        std::vector<int> arr = this->algo.arr_gen();

        start = algo.current_time_nanoseconds();
        algo.heap_sort(arr);
        end = algo.current_time_nanoseconds();

        total = std::abs(end - start);

        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count * 2;

        std::cout << "Count: " << algo.count << "\tTime: " << total << "\tArray sorted!" << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for NLogN");
    plt::legend();
    plt::save("./output/oNLogN.png");
}

void BigO::oN2(){
    std::cout << "\n\n\t---------O(N^2)---------\n\n";
    this->algo.count = std::pow(10, 1);
    this->algo.max = std::pow(10, 4);

    int n = 10, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0 ; i < n; i++) {
        std::vector<int> arr = algo.arr_gen();
        start = algo.current_time_nanoseconds();
        algo.bubbleSort(arr);
        end = algo.current_time_nanoseconds();

        total = std::abs(end - start);

        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count * 2;

        std::cout << "Count: " << algo.count << "\tTime: " << total << "\tArray sorted!" << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for N^2");
    plt::legend();
    plt::save("./output/oN2.png");
}

void BigO::o2N(){
    std::cout << "\n\n\t---------O(2^N)---------\n\n";
    algo.count = 1;
    algo.max = std::pow(10, 4);

    //tower of Hanoi
    std::function<void(int, char, char, char)> towerOfHanoi;
    towerOfHanoi = [&towerOfHanoi](int n, char from_rod, char to_rod, char aux_rod){
        if (n == 1) {  
            cout << "Move disk 1 from rod " << from_rod <<  " to rod " << to_rod<<endl;  
            return;  
        }  
        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);  
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;  
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);  
    };

    int n = 15, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; i++) {
        start = algo.current_time_nanoseconds();
        towerOfHanoi(algo.count, 'A', 'B', 'C');
        end = algo.current_time_nanoseconds();
 
        total = std::abs(end - start);

        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count + 1;

        std::cout << "\n\n\nCount: " << algo.count << "\tTime: " << total << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for 2^N");
    plt::legend();
    plt::save("./output/o2N.png");
}

void BigO::oNFact(){
    std::cout << "\n\n\t---------O(N^2)---------\n\n";
    algo.count = 1;
    algo.max = std::pow(10, 4);

    //factorial function
    std::function<int(int)> fact;
    fact = [&fact](int n)->int{
        if (n <= 1) // base case
            return 1;
        else    
            return n * fact(n-1);
    };

    int n = 15, start, end, total;

    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; i++) {
        start = algo.current_time_nanoseconds();
        int fa = fact(algo.count);
        end = algo.current_time_nanoseconds();

        total = std::abs(end - start);

        y.at(i) = total;
        x.at(i) = algo.count;

        algo.count = algo.count + 1;

        std::cout << "Count: " << algo.count << "\tTime: " << total << "\tAnswer: " << fa << std::endl;
    }

    plt::figure_size(1200, 780);
    plt::plot(x, y);
    plt::named_plot("Big(O)", x, y);
    plt::title("Big(O) for n!");
    plt::legend();
    plt::save("./output/oNFact.png");
}