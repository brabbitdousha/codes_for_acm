class Solution {
public:
    bool jduge(vector<int> a,int l,int r)
    {
        if(l>=r) return true;
        int i=r-1;
        while(i>=l&&a[i]>a[r]) --i;
        
        int k=i;
        while(k>=l)
        {
            if(a[k]>a[r]) return false;
            k--;
        }
        return jduge(a,l,i)&&jduge(a,i+1,r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;
       if(jduge(sequence,0,sequence.size()-1)) {return true;}
        else {return false;}
    }
};