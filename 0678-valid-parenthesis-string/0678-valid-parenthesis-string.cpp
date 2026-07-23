class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
      for(int i=0;i<s.length();i++){
        if(s[i]=='(') {
            max +=1;
            min +=1;
        }
        else if(s[i]==')') {
            max -=1;
            min -=1;
        }
        else {
            max +=1;
            min -=1;
        }
        if(min<0) min=0;
        if(max<0) return false;
      }
      return min == 0;
    }
};