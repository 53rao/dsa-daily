Day 1 : 10/6/2026

## Problem 1 : [Largest element in an array](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1)

```
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int soln=arr[0];
        for(int i=1;i<arr.size();i++){
            if(soln<arr[i]){
                soln=arr[i];
            }
        }
        return soln;
    }
};

```

## Problem 2: [Second Largest](https://www.geeksforgeeks.org/problems/second-largest3735/1)

```
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=-1,slargest=-1;
        for(int num:arr){
            if(largest==-1){
                largest=num;
            }
            else if(largest<num){
                slargest=largest;
                largest=num;
                
            }
            else if(slargest==-1&&largest!=num){
                slargest=num;
            }
            else if(slargest<num&&num!=largest){
                slargest=num;
            }
        }
        return slargest;
    }
};
```

## Problem 3 : [Check if array is sorted and rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

### Optimal  : At max one point prev can be greater than curr elsewhere it should be followed if it sorted and rotated
```
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0,prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<prev){
                if(count==1)
                    return false;
                count++;
            }
            prev=nums[i];       
        }
        if(nums[0]<prev){
            if(count==1)
                return false;
        }
        return true;
    }
};
```

## Problem 4 : [Remove duplicates from sorted array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

### Using extra vector 
#### Leetcode - TC : Beats 15% , SC: beats 15%
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> soln;
        int prev=nums[0],count=1;
        soln.emplace_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prev){
                soln.emplace_back(nums[i]);
                count++;
                prev=nums[i];
            }
        }
        for(int i=1;i<nums.size();i++){
            if(i<soln.size()){
                nums[i]=soln[i];
            }
        }
        return count;
    }
};
```

### Two pointers 
### Leetcode - TC: Beats 100% ,SC beats 18%
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1,right=1,prev=nums[0],count=1;
        while(right<nums.size()){
            while(left<nums.size()&&nums[left]>prev){
                prev=nums[left];
                left++;
                count++;
            }
            right=left+1;
            while(right<nums.size()&&nums[right]<=prev)
                right++;
            if(right>=nums.size())
                break;
            nums[left]=nums[right];
            
            prev=nums[left];
            count++;
            left++;
        }
        return count;
    }
};
```
## Problem 5 and 6 : [](https://leetcode.com/problems/rotate-array/)
### Brute force [Problem 5 - Roatate by 1 place]
```
class Solution {
public:
    void rotatation(vector<int>& nums){
        int temp=nums[nums.size()-1],n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            nums[n-i-1]=nums[n-i-2];
        }
        nums[0]=temp;
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        for(int i=0;i<k;i++){
            rotatation(nums);
        }
    }
};
```
>Fails for 2 cases in the leetcode - TLE
### Additional Vector - [Problem 6 - rotate by d places] Not optimal
#### Leetcode - TC : beats 4%,SC : beats 6%
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> soln(n,0);
        for(int i=0;i<nums.size();i++){
            soln[(i+k)%n]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=soln[i];
        }
    }
};
```
## Problem 7 : [Move zeros to the end](https://leetcode.com/problems/move-zeroes/description/)

### B  Two pointers 
#### Leetcode - TC: Beats 5%, SC: Beats 81%
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,right=1,count=0;
        for(int num:nums){
            if(num==0)
                count++;
        }
        while(right<nums.size()){
            while(left<nums.size()&&nums[left]!=0){
            left++;
            }
            right=left+1;
            while(right<nums.size()&&nums[right]==0){
                right++;
            }
            if(right<nums.size()){
                swap(nums[left],nums[right]);
            }
        }
    }
};
```
### Using extra vector 
#### Leetcode - TC : Beats 100%, SC :Beats 5%

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> soln;
        for(int num:nums){
            if(num!=0){
                soln.emplace_back(num);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<soln.size()){
                nums[i]=soln[i];
            }
            else{
                nums[i]=0;
            }
        }
    }
};
```

## Problem 8 : [Binary Search]()

```
class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int low=0,high=arr.size()-1,mid;
        while(low<=high){
            mid=high-(high-low)/2;
            if(arr[mid]==k)
                return true;
            else if(arr[mid]<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};
```
Day 2 : 11/6/2026

## Problem 9a : [Union of two sorted arrays](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)
### Using set 
#### GeeksforGeeks : Time take : 0.5
```
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int> soln(a.begin(),a.end());
        int i=0,j=0;
        while(j<b.size()){
            soln.insert(b[j]);
            j++;
        }
        return vector<int> (soln.begin(),soln.end());
    }
};
```
### Two pointers
#### GeeksforGeeks : Time take : 0.23
```
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0,j=0,prev;
        vector<int> soln;
        
        if(a[i]==b[j]){
            
            soln.emplace_back(b[j]);
            prev=b[j];
            j++;
            i++;
            
        }
        else if(a[i]>b[j]){
            soln.emplace_back(b[j]);
            prev=b[j];
            j++;
        }
        else{
            soln.emplace_back(a[i]);
            prev=a[i];
            i++;
        }
        
        while(i<a.size()&&j<b.size()){
            if(a[i]<=prev){
                while(a[i]<=prev){
                    i++;
                }
            }
            else if(b[j]<=prev){
                while(b[j]<=prev){
                    j++;
                }
            }
            else if(a[i]==b[j]){
                soln.emplace_back(b[j]);
                prev=b[j];
                j++;
                i++;
            }
            else if(a[i]>b[j]){
                soln.emplace_back(b[j]);
                prev=b[j];
                j++;
            }
            
            else{
                soln.emplace_back(a[i]);
                prev=a[i];
                i++;
            }
        }
        while(i<a.size()){
            if(a[i]<=prev){
                while(a[i]<=prev){
                    i++;
                }
            }
            else{
            soln.emplace_back(a[i]);
                prev=a[i];
                i++;
            }
        }
        while(j<b.size()){
            if(b[j]<=prev){
                while(b[j]<=prev){
                    j++;
                }
            }
            else{
            soln.emplace_back(b[j]);
                prev=b[j];
                j++;
            }
        }
        return soln;
        
    }
};
```

## Problem 9b : [Intersection of two sorted arrays](https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1)
#### GeeksforGeeks : Time take : 0.27

### Two Pointer
```
class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i=0,j=0,prev=-1;
        vector<int> soln;
        while(i<arr1.size()&&j<arr2.size()){
            if((arr1[i]==arr2[j])&&(prev==-1||arr1[i]>prev)){
                soln.emplace_back(arr1[i]);
                prev=arr1[i];
                i++;
                j++;
            }
            else if(arr2[j]>arr1[i]){
                i++;
            }
            else{
                j++;
            }
        }
        return soln;
    }
};
```

## Problem 10 : [268. Missing Number](https://leetcode.com/problems/missing-number/description/)
### Sort and  iterate 
#### Leetcode - TC : beats 21%, SC : beats 93%
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr=0;
        for(int num:nums){
            if(curr!=num)
                return curr;
            curr++;
        }
        return curr;
    }
};
```

## Problem 11 : [485.Max Consecutive ones](https://leetcode.com/problems/max-consecutive-ones/description/)
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0,soln=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                soln=max(soln,curr);
                curr=0;
            }
            else{
                curr++;
            }
        }
        return max(soln,curr);
    }
};
```
## Problem 12 : [560.Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

### prefix sum approach
#### Leetcode - TC : beats 16% , SC : beats 80%
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        prefix.emplace_back(0);
        int curr=0,soln=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            prefix.emplace_back(curr);
        }
        for(int i=0;i<prefix.size();i++){
            for(int j=i+1;j<prefix.size();j++){
                if(prefix[j]-prefix[i]==k)
                    soln++;
            }
        }
        return soln;
    }
};
```

### Hashmap
#### Leetcode - TC : beats 24% , SC : beats 5%

```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int prefix=0,soln=0,need;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            need=prefix-k;
            soln+=mp[need];
            mp[prefix]++;
        }
        return soln;
    }
};
```

## Problem 12 : [Single Number](https://leetcode.com/problems/single-number/description/)
### Hashmap 
#### Leetcode - TC : beats 7% , SC : beats 7%

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second==1)
                return it.first;
        }
        return -1;
    }
};
```
### Sort and iterate
#### Leetcode - TC : beats 23% , SC : beats 23%

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            if(prev==nums[i])
                count++;
            else{
                if(count==1)
                    return prev;
                else{
                    count=1;
                    prev=nums[i];
                }
            }
        }
        return prev;
    }
};
```

## Problem 13 : [Search 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)
### Binary Search
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0,bottom=matrix.size()-1,left,right,midv,midh;
        while(top<=bottom){
            left=0;
            right=matrix[0].size()-1;
            midv=bottom-(bottom-top)/2;
            if(matrix[midv][left]<=target&&target<=matrix[midv][right]){
                while(left<=right){
                    midh=right-(right-left)/2;
                    if(matrix[midv][midh]==target)
                        return true;
                    else if(matrix[midv][midh]<target){
                        left=midh+1;
                    }
                    else{
                        right=midh-1;
                    }
                }
                return false;
            }
            else if(target<matrix[midv][left]){
                bottom=midv-1;
            }
            else{
                top=midv+1;
            }
        }
        return false;
    }
};
```

## Problem 14 : [Row with Max 1s in Rowwise Sorted](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1)

```
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int soln=-1,curr,maxcount=-1;
        for(int i=0;i<arr.size();i++){
            curr=0;
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1)
                    curr++;
            }
            if(curr!=0&&curr>maxcount){
                maxcount=curr;
                soln=i;
            }                
        }
        return soln;
    }
};
```
## Problem 15 : [Sort colors]()
### Hashmap
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int k=0;
        for(auto it:mp){
            int temp=it.second;
            for(int i=0;i<temp;i++){
                nums[k++]=it.first;
            }
        }
    }
};
```
## Problem 16 : [Majority Element]()
### Using hashmap
```class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>n/2)
                return num;
        }
        return 0;
    }
};

```