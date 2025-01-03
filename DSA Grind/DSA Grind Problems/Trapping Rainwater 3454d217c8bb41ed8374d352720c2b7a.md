# Trapping Rainwater

Tags: Arrays, Two Pointers
Level: Hard
Number: 17
Platform: Leetcode

To store Water at an index there must be a >= tower to both left and right of the index.

So we have to find max element to right and max element to left for each index in height vector.

# **APPROACH 1**

- Obtain prefix max and suffix max vector.
- Use the equation to find water trapped.

```cpp
//   Approach 1
 //   TC-->O(N)+O(N)+O(N)= 3*O(N) = O(N)
 //   SC-->O(N)+O(N)= 2*O(N) = O(N)
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> premax(n),suffixmax(n);
        // Computing prefixmax for each element in height array
        premax[0]=height[0];
        for(int i=1;i<height.size();i++)
            premax[i] = max(height[i],premax[i-1]);
        // Computing suffixmax for each element in height array
        suffixmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
           suffixmax[i] = max(height[i],suffixmax[i+1]);
        // computing the water trapped using the below formula
        int water = 0;
        for(int i=0;i<n;i++)
        {
            water += (min(premax[i],suffixmax[i])-height[i]);
        }
        return water;
    }
```

# **APPROACH 2**

**In this approach we use two pointer method.**

```cpp
 //   Approach 2 (Most optimal)
 //   TC-->O(N)
 //   SC-->O(1)
        int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1,water=0;
        int leftmax=0,rightmax=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>leftmax)
                   leftmax = height[l];
                else
                   water+=leftmax-height[l];
                l++;
            }
            else
            {
                if(height[r]>rightmax)
                   rightmax = height[r];
                else
                   water+=rightmax-height[r];
                r--;
            }
        }
        return water;
    }
```