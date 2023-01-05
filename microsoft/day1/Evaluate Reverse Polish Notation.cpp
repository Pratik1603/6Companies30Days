class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    long long res=0;
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                long long b=s.top();
                s.pop();
                long long a=s.top();
                s.pop();
                if(tokens[i]=="+")
                res=a+b;
                 if(tokens[i]=="-")
                res=a-b;
                 if(tokens[i]=="*")
                res=a*b;
                 if(tokens[i]=="/")
                res=a/b;
                s.push(res);
            }
            else
            {
                long long op=stoi(tokens[i]);
                s.push(op);
            }
        }
        return s.top();
    }
        
};

