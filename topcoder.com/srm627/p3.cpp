#include <vector>

class BubbleSortWithReversals {
public:
    int getMinSwaps(vector <int> A, int K) {
        while (K > 0) {
            for (int i = 0; i < A.size(); ++i) {

            }

        }

        return bubbleSort(A);
    }
private:
    int bubbleSort(vector<int>& A) {
        int swaps = 0;
        for (int i = 0; i < A.size()-1; ++i) {
            for (int j = 0; j < A.size()-2; ++j) {
                if (A[j] > A[j+1]) {
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                    swap++;
                }
            }
        }
        return swaps;
    }
};
