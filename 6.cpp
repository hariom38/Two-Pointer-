
//BRUTEFORCE APPROACH
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp;

        // copy first m elements of nums1---->we are not pushing '0' 
        for(int i = 0; i < m; i++){
            temp.push_back(nums1[i]);
        }
        // copy all elements of nums2---->we are not pushing '0'
        for(int i = 0; i < n; i++){
            temp.push_back(nums2[i]);
        }
        // sort the merged array
        sort(temp.begin(), temp.end());

        // copy back to nums1
        for(int i = 0; i < m + n; i++){
            nums1[i] = temp[i];
        }
    }
};
//Time: O((m+n) log(m+n)) (sorting)
//Space: O(m+n) (extra array)





//optimized 
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int left = m - 1;
        int right = 0;

        // Swap elements
        while (left >= 0 && right < n) {
            if (arr1[left] > arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }
        // Sort both arrays
        sort(arr1.begin(), arr1.begin() + m);
        sort(arr2.begin(), arr2.end());

        // Copy arr2 into arr1
        for (int i = 0; i < n; i++) {
            arr1[m + i] = arr2[i];
        }
    }
};
// Time: O(m log m + n log n)
// Space: O(1) (no extra array)





// more OPTIMIZED APPROACH
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3(n+m);
        int i=0;
        int j=0;
        int k=0;

        while(i<m and j<n){
            if(nums1[i]<nums2[j]){
                nums3[k++]=nums1[i++];

            }
            else{
                nums3[k++]=nums2[j++];
            }
        }
        //if there are remaining element of the first array
        while(i<m){
            nums3[k++]=nums1[i++];
        }
         //if there are remaining element of the second array
         while(j<n){
            nums3[k++]=nums2[j++];
         }
          // ✅ Copy back to nums1
        for (int x = 0; x < m + n; x++) {
            nums1[x] = nums3[x];
        }
    }
};// Time Complexity: O(m + n)
// Space Complexity: O(m + n) ❌ (extra array used)


//this is most optimized
// O(m+n), O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
// tc----->O(m+n)
// sc----->o(1)








