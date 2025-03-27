// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.


// the question sayss that we need to pick the lowest price  of a stock on the day and sell it when the price of stock is maximum in future day... the arr is given price of stock on each day. like for day it is 7 , for day 2 is 1 and so on..

//! Bruteforce approach ..
/**
 * the approach is simple first calculate the minimum - with its index. (it will become our buying point)
 * secondly calculate the maximum price - with index (it will become our selling point).
 * keep in mind that .. if price arry is [7,1,5,3,6,4] then buying point is 1(index) and selling point is 4th index... 
 * and last thing we can say like this selling index should always greater then buying index 
 * When the problem says "a different day in the future" it means that the selling day must come after the buying day in the given array
 */

let arr = [7,5, 10, 1, 3, 10];

function minimumPrice(arr) {
    let minimum = Infinity;
    let indexOfMinPrice = -1;
    for (let i = 0; i < arr.length; i++){
        if (arr[i] < minimum) {
            minimum = arr[i];
            indexOfMinPrice = i;
        }
    }
    return {minPrice:minimum,minPriceIndex:indexOfMinPrice}
}
console.log(minimumPrice(arr));

function maximumPrice(arr) {
    let maximum = -Infinity;
    let indexOfMaxPrice = -1;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] >maximum) {
            maximum = arr[i];
            indexOfMaxPrice = i;
        }
    }
    return { maxPrice: maximum, maxPriceIndex: indexOfMaxPrice }
}
console.log(maximumPrice(arr));

function bestTimeToBuyAndSellStocks(arr) {
    
    // step 1 find minimum..
    let buyingPriceObj = minimumPrice(arr);
    console.log("buyingPriceObj : ", buyingPriceObj);
    let buyingPrice = buyingPriceObj.minPrice;
    console.log("bying price is :", buyingPrice);

    let buyingIndex = buyingPriceObj.minPriceIndex;
    console.log("min bying index :", buyingIndex);

    // if buying point exist at the last index. 
    if (buyingIndex === arr.length - 1) {
        return 0;
    }
    // step 2 find the max price after the buying day like if we buy on 0index means 1st day then find the selling price after 1st day.
    let sellingArrayPrice = arr.slice(buyingIndex, arr.length);
    let sellingPriceObj = maximumPrice(sellingArrayPrice);
    console.log("selling price obj: ", sellingPriceObj);
    let sellingPrice = sellingPriceObj.maxPrice;
    console.log("selling price :", sellingPrice);

    let sellingIndex = (sellingPriceObj.maxPriceIndex)+buyingIndex;
    console.log("selling index ", sellingIndex);

    // step 3 return profit. if not then return 0.. 
    return sellingPrice-buyingPrice;

}
console.log("the best time to buy and sell stock is : ", bestTimeToBuyAndSellStocks(arr));

/**
 * time complexity ... 
 * O(n) for min, O(n) for max , O(n) for the slice O(n) so total is O(n).
 * sapce compllexity is O(n) because of slice.
 */


// another burute force is
/**
 * first we will take a variable maxProfit , and profit then we will run a for loop from 0 to arr.length and inside it we will find the minimump value 
 */
let arr1 = [7, 1, 5, 3, 6,4];
//            0  1  2   3  4 5
function bestTimeToBuyAndSellStocksBrute1(arr) {
    let maxProfit = 0;  
    let minValue = arr[0]; 

    for (let i = 1; i < arr.length; i++) {
        minValue = Math.min(minValue, arr[i]);  // here we are passing minValue and current price which is minimum store it..

        let profit = arr[i] - minValue; // calculating the profit.
        // maxProfit = Math.max(maxProfit, profit); // this line means maxprofit or abhi jo profit nikala us mae se badaa wala assing kar0 maxProfit mae .. 
        if (maxProfit < profit) {
            maxProfit = profit;
            console.log("max profi:", maxProfit);
        }
    }

    return maxProfit;
}
console.log(bestTimeToBuyAndSellStocksBrute1(arr1));