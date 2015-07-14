#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> V(10);

    // Use std::iota to create a sequence of integers 0, 1, ...
    std::iota(V.begin(), V.end(), 1);

    // Print the unsorted data using std::for_each and a lambda
    std::cout << "Original data" << std::endl;
    std::for_each(V.begin(), V.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    // Sort the data using std::sort and a lambda
    std::sort(V.begin(), V.end(), [](int i, int j) { return (i > j); });

    // Print the sorted data using std::for_each and a lambda
    std::cout << "Sorted data" << std::endl;
    std::for_each(V.begin(), V.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}

// #include <vector>
// #include <algorithm>
// #include <iostream>

// struct Sum {
//     Sum() { sum = 0; }
//     void operator()(int n) { sum += n; }

//     int sum;
// };

// int main() {
//     std::vector<int> nums{ 3, 4, 2, 9, 15, 267 };

//     std::cout << "before: ";
//     for (auto n : nums) {
//         std::cout << n << " ";
//     }
//     std::cout << '\n';

//     std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

//     // Calls Sum::operator() for each number
//     Sum s = std::for_each(nums.begin(), nums.end(), Sum());

//     std::cout << "after:  ";
//     for (auto n : nums) {
//         std::cout << n << " ";
//     }
//     std::cout << '\n';
//     std::cout << "sum: " << s.sum << '\n';
// }