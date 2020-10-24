Python 3.3.3 (v3.3.3:c3896275c0f6, Nov 18 2013, 21:19:30) [MSC v.1600 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> 20+30*4
140
>>> 20+(30*40)
1220
>>> 15.0/4+(8+3.0)
14.75
>>> (2+3)**3-6/2
122.0
>>> (2+3)*5//4+(4+6)/2
11.0
>>> 12+(3*4-6)/3
14.0
>>> 12+(3**4-6)//2
49
>>> 12*3%5+2*6//4
4
>>> 12%5*3+(2*6)//4
9
>>> x=3
>>> y=x+2
>>> x+=y
>>> print(x,y)
8 5
>>> x=-2
>>> y=2
>>> x+=y
>>> y-=x
>>> print(x,y)
0 2
>>> a=5
>>> b=2*a
>>> a+=a+b
>>> b*=a+b
>>> print(a,b)
20 300
>>> p=10
>>> q=20
>>> p*=q/3
>>> q+=p+q82
Traceback (most recent call last):
  File "<pyshell#26>", line 1, in <module>
    q+=p+q82
NameError: name 'q82' is not defined
>>> q+=p+q*2
>>> print(p)
66.66666666666667
>>> print(q)
126.66666666666667
>>> p=5%2
>>> q=p**4
>>> r=p//q
>>> p+=p+q+r
>>> r+=p+q+r
>>> q-=p+q*r
>>> print(p,q,r)
4 -10 7
>>> p=21//5
>>> q=p%4
>>> r=p*q
>>> p+=p+q-r
>>> r*=p-q+r
>>> q+=p+q
>>> print(p,q,r)
8 8 0
>>> 
