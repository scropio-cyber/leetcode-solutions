class Solution {
public:
bool solve(string &s,string &p,int i,int j)
{
    int m=s.length();
    int n=p.length();
    
    //base case
    if(j==n)
    {
        if(i==m)
        return(true);
        else
        return(false);
    }
    bool match=false;
    if(i<m && ((s[i]==p[j]) || p[j]=='.'))
    match=true;

    if((j+1)<n && p[j+1]=='*')
    {
        //if x*==""
        if(solve(s,p,i,j+2))
        return(true);

        if(match)
        return(solve(s,p,i+1,j));
    }
    
    if(match)
    return(solve(s,p,i+1,j+1));
    else
    return(false);
}
    bool isMatch(string s, string p) {
        return(solve(s,p,0,0));
    }
};