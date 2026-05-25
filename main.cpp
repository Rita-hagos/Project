#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Player {
    string first_name;
    string last_name;
    string team;
};

string fullName(Player p) {
    return p.first_name + " " + p.last_name;
}

// Task 1
vector<string> playersInBothSports(vector<Player> basketball, vector<Player> football) {
    unordered_set<string> basketballNames;
    vector<string> result;

    for (Player p : basketball) {
        basketballNames.insert(fullName(p));
    }

    for (Player p : football) {
        string name = fullName(p);
        if (basketballNames.count(name)) {
            result.push_back(name);
        }
    }

    return result;
}

// Task 2

int missingNumber(vector<int> nums) {
  int n = nums.size();
  int expectedSum = n * (n +1) / 2;
  int actualSum = 0;

for (int num : nums) {
    actualSum += num;
}

return expectedSum - actualSum;
}

//Task 3
int greatestStockProfitit(vector<int> prices)
{
  int lowestPrice = prcies[0];
  int greatestProfit = 0;

for (int price : prcies) {
    int profit = price - lowestPrice;
    greatestProfit = max(greatestProfit, profit);
    lowestPrice = min(lowestPrice, price);
}
    return greatestProfit;
}

//Task 4 
int highestProduct(vector <int> nums) {
  int largest = max (nums[0], nums [1]);
  int secondlargest = min(nums[0], nums[1]);

int smallest = min(nums[0], nums[1]);
int secondSmallest = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        int num = nums[i];

        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest) {
            secondLargest = num;
        }

        if (num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if (num < secondSmallest) {
            secondSmallest = num;
        }
    }

    return max(largest * secondLargest, smallest * secondSmallest); }

//Task 5

vector<double> sortTemperature(vector<double> temps) {
    vector<int> counts(21,0);
    vector <double> sorted;

for (double temp: tempps) {
    int index = (int)(temp * 10) -970;
    counts[index]++;

for (int i = 0; i < counts.size(); i++) {
        while (counts[i] > 0) {
            sorted.push_back((970 + i) / 10.0);
            counts[i]--;
        }
    }

    return sorted;
}

//task 6
int longestConsecutiveSequence(vector<int> nums) {
    unordered_set<int> numbers(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        if (!numbers.count(num - 1)) {
            int current = num;
            int length = 1;

            while (numbers.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {
    vector<Player> basketball = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<Player> football = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    cout << "Task 1: ";
    for (string name : playersInBothSports(basketball, football)) {
        cout << name << " ";
    }
    cout << endl;

    cout << "Task 2: " << missingNumber({2, 3, 0, 6, 1, 5}) << endl;

    cout << "Task 3: " << greatestStockProfit({10, 7, 5, 8, 11, 2, 6}) << endl;

    cout << "Task 4: " << highestProduct({5, -10, -6, 9, 4}) << endl;

    cout << "Task 5: ";
    vector<double> sortedTemps = sortTemperatures({98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1});
    for (double temp : sortedTemps) {
        cout << temp << " ";
    }
    cout << endl;

    cout << "Task 6: " << longestConsecutiveSequence({10, 5, 12, 3, 55, 30, 4, 11, 2}) << endl;

    return 0;
}
