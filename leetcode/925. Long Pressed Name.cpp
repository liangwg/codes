/**/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1=name.size(),len2=typed.size(),i=0,j=0;
        while(i<len1&&j<len2)
        {
            if(name[i]==typed[j])
            {
                i++;j++;
                continue;
            }
            if(name[i]!=typed[j])
            {
                if(i==0||name[i-1]!=typed[j])
                    break;
                j++;
            }
            
        }
        return (i==len1)?true:false;
        
    }
}; 
