// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>
using namespace std;


// C++
int ss(vector<int> &A, int B) {
    int res = 0;
    unordered_map<int, int> freq;
    int left = 0, right = 0;
    
    while (right < A.size()) 
    {
        freq[A[right]]++;
        while (freq.size() > B)
        {
            freq[A[left]]--;
            if (freq[A[left]] == 0) {
                freq.erase(A[left]);
            }
            left++;
        }

        res += right - left + 1;
        right++;
    }
    
    return res;
}

int solve(vector<int> &A, int B) {
    return ss(A, B) - ss(A, B-1);
}




/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int count_all_subarrays_having_upto_K_distinct_ints(int* A, int n1, int B)
{
    int map[n1+1];
	memset(map, 0, (n1 + 1) * sizeof(int));
	int num_of_distinct_ints = 0, res = 0, f = 0;
	int left = 0, right = 0;
	while (left < n1 && right < n1)
	{
		if (f == 0)
		{
			map[A[right]]++;
			if (map[A[right]] == 1)
				num_of_distinct_ints++;
		}
		if (num_of_distinct_ints <= B)
		{
			res += (right - left + 1); // 
			
			right++;
			f = 0;
		}
		if (num_of_distinct_ints > B)
		{
			map[A[left]]--;
			if (map[A[left]] == 0)
				num_of_distinct_ints--;
			left++;
			f = 1;
		}
	} 
    return res;
}

int solve(int *A, int n1, int B)
{

	return count_all_subarrays_having_upto_K_distinct_ints(A, n1, B) - count_all_subarrays_having_upto_K_distinct_ints(A, n1, B - 1);
}

int main()
{								
								//  input	         int A[] = {1, 2, 1, 3, 4};		B = 3				
								//                       (right - left + 1)
								//  1         2             3                           4                        3           = 13
								// [1] -- [1 2] [2] -- [1 2 1] [2 1] [1] -- [1 2 1 3] [2 1 3] [1 3] [3] -- [1 3 4] [3 4]  [4]

								//  input	         int A[] = {1, 2, 1, 3, 4};		B = 3-1		 
								//  1		  2               3                 2           2                                = 10       
								// [1] -- [1 2] [2] -- [1 2 1] [2 1] [1] -- [1 3] [3] -- [3 4]  [4]

																													   //res = 3


	int A[] = {1, 2, 1, 3, 4};  

	// [1 2 1 3] [1 2 1] [1 2] [1] [2] [1] [3] [4] [2 1 3] [2 1] [1 3 4] [1 3] [3 4]
	// int A[] = {1,2,3,4};// [ 1 2 3 4] [1 2 3] [1 2] [ 1 ] [2] [3] [4] [2 3] [2 3 4] [3 4]

	int B = 3;

	auto res = solve(A, sizeof(A) / sizeof(int), B);

	return(0);
}



/* 





*/