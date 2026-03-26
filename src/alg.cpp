// Copyright 2021 NNTU-CS
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
    int left = 0;
    int right = len - 1;
    int total = 0;

    while (left < right)
    {
        int s = arr[left] + arr[right];

        if (s == value)
        {
            if (arr[left] == arr[right])
            {
                int count = right - left + 1;
                total += count * (count - 1) / 2;
                break;
            }
            else
            {
                int leftCount = 1;
                while (left + 1 < right && arr[left] == arr[left + 1])
                {
                    leftCount++;
                    left++;
                }
                
                int rightCount = 1;
                while (right - 1 > left && arr[right] == arr[right - 1])
                {
                    rightCount++;
                    right--;
                }
                
                total += leftCount * rightCount;
                left++;
                right--;
            }
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

int countPairs3(int *arr, int len, int value)
{
    int result = 0;

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
              
                result++;
                int j = mid + 1;
                while (j <= right && arr[j] == target)
                {
                    result++;
                    j++;
                }
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

    return result;
}
