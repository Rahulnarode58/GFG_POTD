''' Proble : Buy Maximum Stocks if i stocks can be bought on i-th day

In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. 

Example 1:
Input:
price = [10,7,19]
k = 45
Output: 
4
Explanation: 
A customer purchases 1 stock on day 1, 2 stocks on day 2 and 1 stock on day 3 for 10, 7 * 2 = 14 and 19 respectively. Hence, total amount is 10 + 14 + 19 = 43 and number of stocks purchased is 4. '''

#Python 
# Coding With Rahul
from typing import List
from heapq import heappush,heappop
class Solution:
    def buyMaximumProducts(self, n : int, k : int, price : List[int]) -> int:
        # code here
        heap =[]
        res = 0
        for i in range (n):
            heappush (heap,(price[i],i+1))
        while heap and k>0:
            minprice,Stock=heappop(heap)
            decision =min (k//minprice,Stock)
            res+=decision
            k-=decision*minprice
        return res
