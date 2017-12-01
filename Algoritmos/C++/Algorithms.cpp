#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>


int betterEnumeration(int A[], int start, int end) {
	int maximum = 0;
	int current = 0;

	for (int i = start; i <= end; i++) {
		current = 0;
		for (int j = i; j <= end; j++) {
			current += A[j];
			if (current > maximum) {
				maximum = current;
			}
		}
	}
	return maximum;
}

/*
Divide N Conquer
*/

int divideHelper(int A[], int start, int mid, int end);
int divideMaxSum(int A[], int start, int end) {
	int mid = 0;
	int leftSum = 0, rightSum = 0, crossSum = 0;
	if (start == end) {
		return A[start];
	}
	else {
		mid = (start + end) / 2;
		leftSum = divideMaxSum(A, start, mid);
		rightSum = divideMaxSum(A, mid + 1, end);
		crossSum = divideHelper(A, start, mid, end);
		if (leftSum >= rightSum && leftSum >= crossSum) {
			return (leftSum < 0 ? 0 : leftSum);
		}
		else if (rightSum >= leftSum && rightSum >= crossSum) {
			return (rightSum < 0 ? 0 : rightSum);
		}
		else {
			return (crossSum < 0 ? 0 : crossSum);
		}
	}
}

int divideHelper(int A[], int start, int mid, int end) {
	int leftSum = -9999;
	int rightSum = -9999;
	int sum = 0;

	for (int i = mid; i >= start; i--)
	{
		sum += A[i];
		if (sum > leftSum) {
			leftSum = sum;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= end; j++) {
		sum += A[j];
		if (sum > rightSum) {
			rightSum = sum;
		}
	}
	return leftSum + rightSum;
}

// Dynamic Algorithm
int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++){

       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
 
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main(int argc, char const *argv[]){
	
	return 0;
}