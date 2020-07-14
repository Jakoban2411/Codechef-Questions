#include<iostream>
#include<string>
#include<stack>
using namespace std;
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
string EvalExp(int* num,int start,int size,int divisor,string Expression="")
{
    char number=num[start]+'0';
    if(start==size-1)
    {
        Expression+=number;
        int X=Evaluate(Expression);
        cout<<X<<"\n";
        if(X%divisor==0)
            return Expression;
        return "NULL";
    }
    string Exp1=Expression+number+"+";
    string Exp2=EvalExp(num,start+1,size,divisor,Exp1);
    if(Exp2!="NULL")
    {
        return (Exp2); 
    }
    Exp1=Expression+number+"*";
    Exp2=EvalExp(num,start+1,size,divisor,Exp1);
    if(Exp2!="NULL")
    {
        return (Exp2); 
    }
    Exp1=Expression+number+"/";
    Exp2=EvalExp(num,start+1,size,divisor,Exp1);
    if(Exp2!="NULL")
    {
        return (Exp2); 
    }
    Exp1=Expression+number+"-";
    Exp2=EvalExp(num,start+1,size,divisor,Exp1);
    if(Exp2!="NULL")
    {
        return (Exp2); 
    }
    return "NULL";
}

int main()
{
    int Numbers[]={1,2,3,3};            //Add a hashmap for faster execution
    int n=11;
    string Exp=EvalExp(Numbers,0,4,n);
    cout<<Exp;
}
