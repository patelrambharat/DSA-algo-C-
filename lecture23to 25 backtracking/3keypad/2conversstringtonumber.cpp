// Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence.



 

// Example 1:

// Input:
// S = "GFG"
// Output: 43334
// Explanation: For 'G' press '4' one time.
// For 'F' press '3' three times.
// Example 2:

// Input:
// S = "HEY U"
// Output: 4433999088
// Explanation: For 'H' press '4' two times.
// â€‹For 'E' press '3' two times. For 'Y' press '9' 
// three times. For white space press '0' one time.
// For 'U' press '8' two times.
 

// Your Task:  
// You dont need to read input or print anything. Complete the function printSequence() which takes a string as input parameter and returns its equivalent mobile numeric keypad sequence as a string.
 

// Expected Time Complexity: O(Length of String)
// Expected Auxiliary Space: O(Length of String)
 

// Constraints:

// 1 <= Length of String <= 105
// Characters of string can be empty space or capital alphabets.



string printSequence(string S)
{
    //code here.
      string str[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
   
   
   string ans = "";
   for (int i = 0; i < S.length(); i++)
   {

       if (S[i] == ' ')
       {
           ans = ans + '0';
       }
       else
       {
           ans = ans + str[S[i] - 'A'];
       }
   }
   return ans;
}