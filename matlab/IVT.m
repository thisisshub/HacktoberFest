clc 
clear all 
close all
syms x;

%% change this block
f=@(x) exp(x)-x^2+3*x-2; %change this acc to ques
h=1; %change this acc to ques

%% 
a=0;
b=1;

%IVT
for i= -10:h:10
    if f(i)*f(i+h)<0
        a=i;
        b=i+h;
    end
end
a
b
