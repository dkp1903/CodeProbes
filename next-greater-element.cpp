#define vector<int> vi;

vi NGE(vi a)
{    
    stack<int>s;    
    vi next(a.size());    
    int n = a.size();    
    for(int i = n-1; i >= 0; i--)    
    {        //Removing the smaller elements            

        while(!s.empty() && s.top() <= a[i])            
            s.pop();

        // If the stack is empty, it means that this element is 
        // the largest one encountered so far.         
        // Thus, its next will be -1.        
        if(s.empty())            
            next[i] = -1;

        // If there’s a larger element, it’ll be the next for all 

        //elements, until a larger one comes.        
        else            
            next[i] = s.top();

        s.push(a[i]);    
    }

    return next;
}
