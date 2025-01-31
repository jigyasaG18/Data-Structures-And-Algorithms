Rock Paper Scissors
The RPS world championship is here. Here two players A and B play the game. You need to determine who wins.
Both players can choose moves from the set {R,P,S}.
The game is a draw if both players choose the same item.
The winning rules of RPS are given below:
Rock crushes scissor
Scissor cuts paper
Paper envelops rock
 
Example 1:
Input:
S = "RR"
Output: DRAW
Explanation: Both A and B chooses a Rock. Hence, it's a draw.

Example 2:
Input: 
S = "RS"
Output: A
Explanation: A chose a Rock whereas B chose a Scissor. Rock crushes the Scissor and thus, A wins.

Your Task:
You don't need to read input or print anything. Your task is to complete the function gameResult() which takes the string S as input and returns a string denoting the answer. Return "A" if A wins, "B" if B wins and "DRAW" if it's a draw.



class Solution
{
  public:
    string gameResult (string s)
        {
            //code here.
              for(int i=0;i<s.length();i++){
                if(s[0]==s[1]){
                    return"DRAW";
                }
                else if(s[0]=='R'&&s[1]=='S'||s[0]=='P'&&s[1]=='R'||s[0]=='S'&&s[1]=='P'){
                    return "A";
                    
                }
                else{
                    return "B";
                }}
        }
};