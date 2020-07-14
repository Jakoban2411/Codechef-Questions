int Evaluate(string Expression)
{
    stack<int> Nums;
    stack<char> Ops;
    for(int i=0;i<Expression.length();i++)
    {
        switch(Expression[i])
        {
            case '+':
                        Ops.push(Expression[i]);
                        break;
            case '-':
                        while(!Ops.empty() && Ops.top()=='+')
                        {
                            int Num1=Nums.top();
                            Nums.pop();
                            int Num2=Nums.top();
                            Nums.pop();
                            Nums.push(Num1+Num2);
                            Ops.pop();
                        }
                        Ops.push(Expression[i]);
                        break;
            case '*':   
                        while(!Ops.empty() && (Ops.top()=='+'||Ops.top()=='-'))
                        {
                            int Num1=Nums.top();
                            Nums.pop();
                            int Num2=Nums.top();
                            Nums.pop();
                            if(Ops.top()=='+')
                                Nums.push(Num1+Num2);
                            else
                                Nums.push(Num2-Num1);
                            Ops.pop();
                        }
                        Ops.push(Expression[i]);
                        break;
            case '/':
                        
                        while(!Ops.empty() && (Ops.top()=='+'||Ops.top()=='-'||Ops.top()=='*'))
                        {
                            int Num1=Nums.top();
                            Nums.pop();
                            int Num2=Nums.top();
                            Nums.pop();
                            if(Ops.top()=='+')
                                Nums.push(Num1+Num2);
                            if(Ops.top()=='-')
                                Nums.push(Num2-Num1);
                            if(Ops.top()=='*')
                                Nums.push(Num2*Num1);
                            Ops.pop();
                        }
                        Ops.push(Expression[i]);
                        break;
            default:
                        Nums.push(Expression[i]-'0');
        }
    }
    if(!Ops.empty())
    {
        while(!Ops.empty())
        {
            int Num1=Nums.top();
            Nums.pop();
            int Num2=Nums.top();
            Nums.pop();
            char Op=Ops.top();
            Ops.pop();
            switch(Op)
            {
                case '+':
                            Nums.push(Num1+Num2);
                            break;
                case '-':
                            Nums.push(Num2-Num1);
                            break;
                case '*':
                            Nums.push(Num1*Num2);
                            break;
                case '/':
                            Nums.push(Num2/Num1);
                            break;
            }
        }
    }
    return Nums.top();
}
