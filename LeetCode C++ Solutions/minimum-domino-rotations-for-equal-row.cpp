/**
 * Author: Siddhant Pandya
 * Problem: 1007. Minimum Domino Rotations For Equal Row
 */

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int i=A[0],j=B[0];
        int same,count1=0,count2=0;
        int flag=0;
        
        if(i==A[1] || i==B[1])
        {
            same=i;
        }
        else if(j==A[1] || j==B[1])
        {
            same=j;
        }
        else
        {
            return -1;
        }
            
        for(int x=0;x<A.size();x++)
        {
            if(!(A[x]==same || B[x]==same))
            {
                flag=1;
                break;
            }
            
            if(x==A.size()-1){flag=2;   }
            
            if(A[x]!=same)
            {
                count1++;
                continue;
            }
            else if(B[x]!=same)
            {
                count2++;
                continue;
            }
            
        }
        if(flag==0){return -1;}
        else if(flag==1)
        {
            same=j;
            count1=0;
            count2=0;
            
            for(int x=0;x<A.size();x++)
        {
            if(!(A[x]==same || B[x]==same))
            {
                return -1;
            }
                        
            if(A[x]!=same)
            {
                count1++;
                continue;
            }
            else if(B[x]!=same)
            {
                count2++;
                continue;
            }   
        }
        }
        
        if(count1<count2){return count1;    }
        return count2;
    }
};