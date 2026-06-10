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