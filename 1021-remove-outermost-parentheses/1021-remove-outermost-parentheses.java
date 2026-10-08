class Solution {
    public String removeOuterParentheses(String p) {
        int c = 0;
        StringBuilder s = new StringBuilder();

        for (int i = 0; i < p.length(); i++) {

            if (p.charAt(i) == ')')
                c--;

            if (c != 0)
                s.append(p.charAt(i));

            if (p.charAt(i) == '(')
                c++;
        }

        return s.toString();
    }
}