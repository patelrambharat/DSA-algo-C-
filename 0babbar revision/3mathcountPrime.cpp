class Solution {
public:
    int countPrimes(int n) {
          vector <bool> v (n+1,true);
        int c=0;
        v[0] = v[1] = false;

        for(int i=2; i<n; i++)
        {
            if(v[i] == true)
            {
                for(int j=2*i; j<n; j=j+i)
                    v[j] = false;
            }

            if(v[i] == true)
                c++;
        }

        return c;
    }
};
class Solution {
public:
    int countPrimes(int n) {
          vector <bool> v (n+1,true);
        int c=0;
        v[0] = v[1] = false;
        
        for(int i=2; i<n; i++)
        {
            if(v[i] == true)
            {
                for(int j=2*i; j<n; j=j+i)
                    v[j] = false;
            }
            
            if(v[i] == true)
                c++;
        }
        
        return c;
    }
};