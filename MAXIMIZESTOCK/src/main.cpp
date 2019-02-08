#include <iostream>
#include <vector>

using namespace std;

struct date {
	int BUY_DATE;
	int SELL_DATE;
};

void findDateSet(vector<date>&finalDates, date &currDates, int dates[], int currPos, int length) {
	if (currPos > length) {
		return;
	}
	if (currPos == 0) {
		currDates.BUY_DATE = currPos;
		findDateSet(finalDates, currDates, dates, currPos + 1, length);
	}
	else if (dates[currPos] > dates[currDates.BUY_DATE]) {
		currDates.SELL_DATE = currPos;
		findDateSet(finalDates, currDates, dates, currPos + 1, length);
	} else {
		finalDates.push_back(currDates);
		currDates.SELL_DATE = currPos - 1;
		currDates.BUY_DATE = currPos;
		findDateSet(finalDates, currDates, dates, currPos + 1, length);
	}

}

void maximizeProfits(int dates[], int size) {
	vector<date> finalDates;
	date currDates;
	findDateSet(finalDates, currDates, dates, 0, size);

	for (int i = 0; i < finalDates.size(); i++) {
		printf("Buy on day: %dt Sell on day: %dn", finalDates[i].BUY_DATE,finalDates[i].SELL_DATE); 
		// cout << "Buy Date: " << finalDates[i].BUY_DATE << " Sell Date: " << finalDates[i].SELL_DATE << endl;
	}
}

int main() {
	int foo[7] = {
		100, 180, 260, 210, 40, 535, 695
	};
	maximizeProfits(foo, 7);
	return 0;
}