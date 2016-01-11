//Finding the max profit from a series of stocks.
//If only two stocks are presented, then only one answer can be provided.

//Runtime: O(n)
//Explanation:  This code cycles through the entire array once.  
//The runtime is dependent on the length of the array only.

#include <iostream>

//We'll optionally return the buy and sell points.
int GetMaxProfit(int stocks[], int numStocks, int& buy, int& sell)
{
    buy = 0;
    sell = 0;

    if(numStocks < 2)
        return 0;

    if(numStocks == 2)
        return stocks[1] - stocks[0];

    int max_profit = 0;
    buy = stocks[0];

    //Stocks are presented in chronological order.  The aim is to buy low and sell
    //high, and the sale must occur after the purchase.
    for(int i = 0; i < numStocks; i++)
    {
        if(stocks[i] <= 0)
        {
            buy = 0;
            return 0; //stocks aren't free, nor do you have to pay to sell them (or earn to buy them).
        }

        if(stocks[i] < buy)
            buy = stocks[i];
        else
        {
            if((stocks[i] - buy) > max_profit)
            {
                sell = stocks[i];
                max_profit = stocks[i] - buy;
            }
        }
    }

    return max_profit;
}

int main()
{
    int stocks[] = {3, 8, 12, 4, 8, 1, 9, 5};
    int buy, sell;

    int max_profit = GetMaxProfit(stocks, (sizeof(stocks) / sizeof(int)), buy, sell);
    std::cout << "Max profit: " << max_profit << std::endl << std::endl;

    //Run tests
    int stocks1[] = {5, 9, 4, 6, 1, 10}; //Max profit should be 9: buy at 1 and sell at 10.
    std::cout << "STOCKS: {5, 9, 4, 6, 1, 10}: ";
    max_profit = GetMaxProfit(stocks1, (sizeof(stocks1) / sizeof(int)), buy, sell);
    std::cout << "Buy at " << buy << " and sell at " << sell << " for maximum profit of " << max_profit;
    if(max_profit == 9 && buy == 1 && sell == 10)
        std::cout << " PASS" << std::endl;
    else
        std::cout << " FAIL" << std::endl;

    int stocks2[] = {6, 1, 19, 86000, 90000, 1}; //Max profit should be 89999: buy at 1 and sell at 90000.
    std::cout << "STOCKS: {6, 1, 19, 86000, 90000, 1}: ";
    max_profit = GetMaxProfit(stocks2, (sizeof(stocks2) / sizeof(int)), buy, sell);
    std::cout << "Buy at " << buy << " and sell at " << sell << " for maximum profit of " << max_profit;
    if(max_profit == 89999 && buy == 1 && sell == 90000)
        std::cout << " PASS" << std::endl;
    else
        std::cout << " FAIL" << std::endl;

    int stocks3[] = {1}; //Invalid
    std::cout << "STOCKS: {1}: ";
    max_profit = GetMaxProfit(stocks3, (sizeof(stocks3) / sizeof(int)), buy, sell);
    std::cout << "Buy at " << buy << " and sell at " << sell << " for maximum profit of " << max_profit;
    if(max_profit == 0 && buy == 0 && sell == 0)
        std::cout << " PASS" << std::endl;
    else
        std::cout << " FAIL" << std::endl;

    int stocks4[] = {1, -1, 0}; //Max profit should be 9: buy at 1 and sell at 10.
    std::cout << "STOCKS: {1, -1, 0}: ";
    max_profit = GetMaxProfit(stocks4, (sizeof(stocks4) / sizeof(int)), buy, sell);
    std::cout << "Buy at " << buy << " and sell at " << sell << " for maximum profit of " << max_profit;
    if(max_profit == 0 && buy == 0 && sell == 0)
        std::cout << " PASS" << std::endl;
    else
        std::cout << " FAIL" << std::endl;

    std::cin.get();
    return 0;
}