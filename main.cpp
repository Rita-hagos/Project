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
  int secondlargest
