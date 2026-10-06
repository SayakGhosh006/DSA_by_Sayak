class Solution {
public:
    int minAddToMakeValid(string s) {
        int c1=0,c2=0;
         for(char ch:s){
            if(ch=='(')
             c1++;
             else {
                if(c1>0) c1--;
                else c2++;
             }
         }
         return c1+c2;
    }
};
