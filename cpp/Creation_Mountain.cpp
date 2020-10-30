#include<stdio.h>
#include<iostream>
#include<string>
#include<ctype.h>
#include<math.h>
using namespace std;
int main() {
	string a , b;
  cout << "Creation_Mountain" << endl;
  cout << "first, you must fill a number of  Mountains and second, you could fill hight of each mountains spit by space bar" << endl ;
	getline(cin, b);
  getline(cin, a);
	if(b.size() != 0){
    long long i = stoi(b)  , j , k;
    long long o[i] ;
    long long stt, stp , mou ,runt;
    long long num[4] = {0,0,0,0}; //number serises (num)=>0 , max value (mx) =>1 , min value (mi) =>2 , overall len (ml) =>3
    if( (stof(b) - floor(stof(b)) == 0 )&& i >= 0) {
    	b.clear();
    	if(i > 0){
    	for(char c : (a+" ")){
        	if(c == ' '){
            	o[num[0]] = stoi(b);
            	num[1] = (o[num[0]] > num[1]) ? o[num[0]] : num[1];
            	num[2] = (o[num[0]] < num[2]) ? o[num[0]] : num[2];
            	num[3] += abs(o[num[0]]);
            	b.clear();
            	num[0] += 1;
            }
        	else {
            	b = b+c;
            }
        }}
    	if(i == 0){}
    	else if(num[0] == i){
    	   mou = abs(o[0]);
    	   for(i = 0 ; i < num[1]-1 ; i++){
    	       stt = num[1] - i ;
    	       stp = mou + (mou - num[1] + i );
    	       runt = stt;
    	       for(j = 0 ; j < num[0] ; j++){
    	         //  cout << j << endl;
    	           mou = abs(o[j]);
    	           for(k = 1 ; k < ((mou*2))  ; k++){
    	               if(o[j] >= 0){
    	              // if((mx - o[j] -1) <= (k-1)){
    	               if(runt == k && runt <= stp){
    	                   cout << "*";
    	                   runt += 2;
    	               }
    	               else {
    	                   cout << " ";
    	               }
    	              }
    	               else {
    	                   cout << " ";
    	              }
    	               if( k == (mou*2)-1){
    	                   cout << " ";
    	               }
    	           }
    	           if(j == ( num[0]-1)){
    	               mou = abs(o[0]);
    	               stt = num[1] - i ;
    	                stp = mou + (mou - num[1] + i );
    	                runt = stt;
    	           }
    	           else {
    	               mou = abs(o[j+1]);
    	               stt = num[1] - i ;
    	                stp = mou + (mou - num[1] + i );
    	                runt = stt;
    	           }
    	       }
    	       cout << "" << endl ;
    	   }
    	   for(i = 0 ; i < num[3] ; i++ ){
    	       cout << "* ";
    	   }
    	   cout << endl;
    	   mou = abs(o[0]);
    	   num[2] = abs(num[2]);
    	   for(i =  num[2]-2 ; i >= 0 ; i--){
    	       stt = num[2] - i ;
    	       stp = mou + (mou -num[2] + i );
    	       runt = stt;
    	       for(j = 0 ; j < num[0] ; j++){
    	           mou = abs(o[j]);
    	           for(k = 1 ; k < ((mou*2))  ; k++){
    	               if(o[j] <= 0){
    	               if(runt == k && runt <= stp){
    	                   cout << "*";
    	                   runt += 2;
    	               }
    	               else {
    	                   cout << " ";
    	               }
    	              }
    	               else {
    	                   cout << " ";
    	              }
    	               if( k == (mou*2)-1){
    	                   cout << " ";
    	               }
    	           }
    	           if(j == (num[0]-1)){
    	               mou = abs(o[0]);
    	               stt = num[2] - i ;
    	                stp = mou + (mou -num[2] + i );
    	               runt = stt;
    	           }
    	           else {
    	               mou = abs(o[j+1]);
    	               stt = num[2] - i ;
    	                stp = mou + (mou -num[2] + i );
    	               runt = stt;
    	           }
    	       }
    	       cout << "" << endl ;
    	   }

    	}
    	else {
    	    cout << "Error";
    	}

   }
	else { printf("Error");}
    }
    else {
    	    cout << "Error";
    	}

    return 0;
}
