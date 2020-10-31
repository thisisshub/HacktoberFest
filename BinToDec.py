def binDec(n):
    num = int(n);
    value = 0;
    base = 1;
    flag = num;
    while(flag):
        l = flag%10;
        flag = int(flag/10);
        print(flag);
        value = value+l*base;
        base = base*2;
    return value
num = input();
a = binDec(num);
print(a)
        
