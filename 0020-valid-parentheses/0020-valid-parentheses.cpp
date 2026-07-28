class Solution {
public:
    bool isValid(string arr) {

        stack<char> st;

        int n = arr.size();

        for(int i = 0; i < n; i++) {

            if(arr[i] == '(' ||
               arr[i] == '[' ||
               arr[i] == '{') {

                st.push(arr[i]);
            }
            else {

                if(st.empty())
                    return false;

                char ch = st.top();

                if((arr[i] == ')' && ch == '(') ||
                   (arr[i] == '}' && ch == '{') ||
                   (arr[i] == ']' && ch == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};