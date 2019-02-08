#include <iostream>
#include <vector>

using namespace std;

struct numberComparision {
	int GREATER_NUM;
	int LESSER_NUM;
	bool ORDER_CHANGED;
};

numberComparision compareNumbers(int num1, int num2) {
	numberComparision comparison;
	if (num1 > num2) {
		comparison.GREATER_NUM = num1;
		comparison.LESSER_NUM = num2;
		comparison.ORDER_CHANGED = true;
	} else {
		comparison.GREATER_NUM = num2;
		comparison.LESSER_NUM = num1;
		comparison.ORDER_CHANGED = false;
	}

	return comparison;
}

void bubbleSort(int *unsortedList, int size) {
	//to make faster replace with better sorting. Modified Merge sort?
	for (int i = 0; i < size; i++) {
		for (int t=0; t < size - 1; t++) {
			numberComparision comparison;
			comparison = compareNumbers(*(unsortedList + t), *(unsortedList + t+1));
			*(unsortedList + t) = comparison.LESSER_NUM;
			*(unsortedList + t + 1) = comparison.GREATER_NUM;
		}

	}
}
void getTriples(int *list, int size, int sum) {
	bubbleSort(list, size);

	int ans = 0; 
  
    for (int i = 0; i < size - 2; i++) { 
       
        int j = i + 1;
		int k = size - 1; 
  
        while (j < k) { 

            if (*(list + i) + *(list + j) + *(list + k) >= sum) {
                k--; 
  
			} else { 
                ans += (k - j); 
                j++; 
            } 
        } 
    } 
    cout <<  ans << endl; 
	
}

int main() {
	 
	int test[] = {-2, -5, 4, 3};
	int *p = test;
	int size = sizeof(test)/sizeof(int);
	int sum = 2;
	getTriples(p, size, sum);
	
	return 0;
}