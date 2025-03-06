
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    vector<double> numbers;
    double num;
    
    cout << "Enter a series numbers:" << endl;
    while (cin >> num && num != 0) {
        numbers.push_back(num);
    }
    
    if (numbers.empty()) {
        cout << "No numbers entered." << endl;
        return 0;
    }
    
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::min();
    double sum = 0;
    double sum_squares = 0;
    
    for (double number : numbers) {
        if (number < smallest) smallest = number;
        if (number > largest) largest = number;
        sum += number;
        sum_squares += number * number;
    }
    
    int N = numbers.size();
    double average = sum / N;
    double standard_deviation = sqrt(sum_squares / N - average * average);
    
    cout << "smallest:" << smallest << endl;
    cout << "largest:" << largest << endl;
    cout << "average:" << average << endl;
    cout << "standard_deviation:" << standard_deviation << endl;
    
    return 0;
}