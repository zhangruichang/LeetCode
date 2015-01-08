typedef unsigned long long ULL;

vector<ULL> Factorial(int n)
{
    if(n==1) return {1};
    auto ans=Factorial(n-1);
    reverse(ans.begin(), ans.end());
    ULL ansn=(ULL)ans.size();
    ULL c=0;
    for(int i=0;i<ansn;i++)
    {
        ans[i]=ans[i]*(ULL)n+c;
        c=ans[i]/10;
        ans[i]%=10;
    }
    if(c) ans.push_back(c);
    reverse(ans.begin(), ans.end());
    return ans;
}