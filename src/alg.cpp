// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
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
    
    // Бинарный поиск - средний по скорости O(n log n)
    for (int i = 0; i < len; i++)
    {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target)
            {
                total++;
                break;
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
        int s = arr[left] + arr[right];

        if (s == value)
        {
            total++;
            left++;
            right--;
        }
        else if (s < value)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return total;
}
