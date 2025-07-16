/*
maximum product subarray

Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the answer fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10*/



// User function Template for C++
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size(), i = 0, j = 0, prod = 0, ans = 0;
        if (n==1){
            return arr[0];
        }
        while (j <= n){
            if (j==n || arr[j]==0){
                if (prod>0){
                    ans = max(ans, prod);
                } else if (i==j-1){
                    ans = max(ans, 0);
                } else {
                    int prod1 = prod, prod2 = prod;
                    for (int k=j-1; k>=i && prod1<0; k--){
                        prod1 = prod1/arr[k];
                    }
                    for (int k=i; k<=j-1 && prod2<0; k++){
                        prod2 = prod2/arr[k];
                    }
                    ans = max(ans, max(prod1, prod2));
                }
                i = j+1;
                prod = 0;
            } else {
                if (prod == 0){
                    prod = arr[j];
                } else {
                    prod = prod*arr[j];   
                }
            }
            j++;
        }
        
        return ans;
    }
};
/*class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
       

        int  n=arr.size();

    int c=0;
    for(int i=0;i<n;i++)
    { if(arr[i]<0)
       c++;
    }
    int temp[100];
    int j=0;
    if(c%2!=0)
    { for(int i=0;i<n;i++)
       { if(arr[i]<0)
         { 
            temp[j]=arr[i];
 
    
       min=temp[i];
    }
    int res=1;
    
     for(int i=0;i<n;i++)
       { if(arr[i]!=0 && arr[i]!=min)
         { res*=arr[i];
         
          }
          else
          break;
       }
       
         
        
        return res;
    }
};
*/
