class Calculator():
    def power(self,n,p):
        try:
            if n <0 or p <0:
                return "n and p should be non-negative"
            else:
                return pow(n, p)
        except ValueError:
            print(ValueError)


myCalculator=Calculator()
T=int(input())
for i in range(T):
    n,p = map(int, input().split())
    try:
        ans=myCalculator.power(n,p)
        print(ans)
    except Exception as e:
        print(e)