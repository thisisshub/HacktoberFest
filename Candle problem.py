#Solution for given problem:
#You need 1231 candles for a celebration. Each candle costs Rs 14. However, the shop gives a candle
#free for every 17 paid candles. No free candle is given for a set of less than 17 candles. Write a
#Python command script that asks the user to input the number of candles they need. Then it prints
#the number of candles the user should purchase after taking note of the free candles offer. (In some
#cases, you will have one spare but unneeded candle!). Print your net saving due to the free candles
#offer (Do not count any unneeded candle as a saving.)

n=int(input("Enter the no. of candles you need"))
count=0
while n>17:
    n=n-17
    count+=1
    n-=1
price=count*17*14+n*14
saving=14*count
print("The price you need to pay",price)
print("you saved Rs",saving)

