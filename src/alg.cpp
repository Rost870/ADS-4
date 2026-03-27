// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr,int len,int value)
{
    int total = 0;

        for (int a = 0; a < len; a++)
        {
            for (int b = a + 1; b < len; b++)
            {
                if (arr[a] + arr[b] == value)
                    total++;
            }
        }

        return total;
}


int countPairs2(int *arr, int len, int value)
{
    int total = 0;

    for (int i = 0; i < len; i++)
    {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;

     
        int pos = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                pos = mid;
                right = mid - 1;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

       
        if (pos != -1)
        {
            int k = pos;
            while (k < len && arr[k] == target)
            {
                total++;
                k++;
            }
        }
    }

    return total;
}
int countPairs3(int *arr, int len, int value)
{
    int left = 0;
    int right = len - 1;
    int total = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum < value)
        {
            left++;
        }
        else if (sum > value)
        {
            right--;
        }
        else
        {
            if (arr[left] == arr[right])
            {
                int n = right - left + 1;
                total += n * (n - 1) / 2;
                break;
            }

            int leftVal = arr[left];
            int rightVal = arr[right];

            int countLeft = 0;
            int countRight = 0;

            while (left < right && arr[left] == leftVal)
            {
                countLeft++;
                left++;
            }

            while (right >= left && arr[right] == rightVal)
            {
                countRight++;
                right--;
            }

            total += countLeft * countRight;
        }
    }

    return total;
}
