// Problem statement
// Ninja is planning to make dessert. For which he is going to buy ingredients. There are ‘N’ base flavors and ‘M’ toppings. Ninja has a target that he will be needing an amount of ‘K’ for making the dessert.

// For making dessert, there are some basic rules

// 1. There should be exactly one base flavor.
// 2. Toppings can be one or more or none.
// 3. There are at most two toppings of each type.
// Ninja wants to make a dessert with a total cost as close to the target price as possible.

// You will be given an array/list flavor of size N representing the cost of each base flavor and another array/list toppings of size 'M' representing the cost of each topping and the target price.

// Your task is to help Ninja to find the closest possible cost of the dessert to the target price 'K'. If there are multiple answers, return the lower one.

// Example

// Let N = 2 , M = 2 , K = 10, FLAVOR = [1,7] , TOPPING = [3, 4] , K = 10

// Here we can make a dessert with the base flavor of price 7 and adding 1 topping of price 3. Which will cost 7 + 3 = 10, which is exactly equal to k, so the closest possible price would be 10.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints
// 1 <= T <= 5
// 1 <= N, M <= 10
// 1 <= FLAVOUR[i] , TOPPINGS[i] <= 10 ^ 4
// 1 <= K <= 10 ^ 4 

// Time limit: 1 sec.
// Sample Input 1
// 2
// 2
// 1 7
// 3
// 1 2 3
// 10
// 1
// 10
// 3
// 5 6 11
// 9
// Sample Output 1
// 10
// 10
// Explanation
// Test case 1

// In this case, Ninja has 2 base flavours of cost 1 and 7,  and 3 toppings of price 1 and 2. Here target price is 10. So if Ninja takes a base of cost 7 and 1 topping of cost 3, then Ninja can make a dessert exactly of cost 10 ( 7 + 3), i.e., target price.

// Test case 2

// In this case, Ninja has only one base flavour of cost 10 and 3 toppings of 5, 6, 11. To make the dessert, Ninja must need a base, so 10 is the minimum cost that he must spend. Now, if he will add toppings price will rise further. So the closest possible price is 10.
// Sample Input 2:
// 2
// 4
// 1 8 3 4
// 3
// 2 3 4
// 20
// 1
// 2
// 1
// 2
// 7
// Sample Output 2:
// 20
// 6

#include <bits/stdc++.h> 
int bestCost;  // Global variable to store the best cost

// Helper function to try all combinations of toppings
void findClosestCost(const vector<int>& toppings, int currentCost, int target, int index) {
    // Update the bestCost if the currentCost is closer to the target
    if (abs(currentCost - target) < abs(bestCost - target) ||
        (abs(currentCost - target) == abs(bestCost - target) && currentCost < bestCost)) {
        bestCost = currentCost;
    }

    // If we've tried all toppings, return
    if (index == toppings.size()) {
        return;
    }

    // Explore the choices of taking 0, 1, or 2 of the current topping
    findClosestCost(toppings, currentCost, target, index + 1);  // Take 0 of this topping
    findClosestCost(toppings, currentCost + toppings[index], target, index + 1);  // Take 1 of this topping
    findClosestCost(toppings, currentCost + 2 * toppings[index], target, index + 1);  // Take 2 of this topping
}
int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    bestCost = baseCosts[0];  // Initialize the best cost with the first flavor
    
    // Try each base flavor and find the closest cost using toppings
    for (int flavor : baseCosts) {
        findClosestCost(toppingCosts, flavor, target, 0);
    }
    
    return bestCost;
}
