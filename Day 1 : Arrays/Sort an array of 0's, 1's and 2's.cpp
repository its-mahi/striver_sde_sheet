/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * 
 * Problem Statement : 
 *      You have been given an integer array/list(ARR) of size 'N'. It only contains Os, 1s and 2s.
 *      Write a solution to sort this array/list.
 * 
 *      Note:
 *          Try to solve the problem in 'Single Scan' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
 * 
 * 
 * Difficulty : Easy
*/


#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
