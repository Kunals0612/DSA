class Solution{
    public:
        vector<int> findUnion(vector<int>& num1, vector<int>& num2){
            vector<int> union;
            int n = num1.size();
            int m = num2.size();

            int i = 0, j = 0;

            while(i < n && j < m){
                if(num1[i] <= num2[j]){
                    if(union.size() == 0 || union.back() != num1[i]){
                        union.push_back(num1[i]);
                        i++;
                    }
                }else{
                    if(union.size() == 0 || union.back() != num2[j]){
                        union.push_back(num2[j]);
                        j++;
                    }
                }
            }

            while(i < n){
                if(union.back() != num1[i]){
                    union.push_back(num1[i]);
                }
                i++;
            }

            while(j < m){
                if(union.back() != num2[j]){
                    union.push_back(num2[j]);
                }
                j++;
            }

            return union;
        }
};