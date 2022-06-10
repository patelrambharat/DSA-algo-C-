
// 320. Generalized Abbreviation
// Write a function to generate the generalized abbreviations of a word.

// Example:

// Given word ="word", return the following list (order does not matter):

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
// Solution:


#include <bits/stdc++.h>

void coreSolve(vector<string> &tank,string temp,string &str,int index,int count)

{

 

if(index==str.length())

{

  if(count>0)

  {

    temp+=to_string(count);

  }

  tank.push_back(temp);

  return;

}

 

if(count>0)

{

  coreSolve(tank,temp+to_string(count)+str[index],str,index+1,0);  //yha pe character dal rhe hai

}

else

{

  coreSolve(tank,temp+str[index],str,index+1,count);    //yha pe - wala chij dal rhe hai

}

 

coreSolve(tank,temp,str,index+1,count+1);   //skip wala kam yha 

}


vector < string > findAbbr(string & str)

{

   vector<string> tank;

   string temp;

   coreSolve(tank,temp,str,0,0);

   sort(tank.begin(),tank.end());  

   return tank;
}