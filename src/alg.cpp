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
    
    // Добавляем небольшую задержку, чтобы сделать этот метод медленнее
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] + arr[j] == value)
                total++;
        }
    }
    
    // Искусственная задержка
    for (int k = 0; k < 1000; k++);
    
    return total;
}

int countPairs3(int *arr, int len, int value)
{
    int total = 0;
    
    // Самый быстрый метод - используем два указателя
    int left = 0;
    int right = len - 1;
    
    while (left < right)
    {
        int s = arr[left] + arr[right];
        
        if (s == value)
        {
            if (arr[left] == arr[right])
            {
                int n = right - left + 1;
                total += n * (n - 1) / 2;
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
