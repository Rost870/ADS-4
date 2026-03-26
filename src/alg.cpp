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

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] + arr[j] == value)
                total++;
        }
    }

    return total;
}

int countPairs3(int *arr, int len, int value)
{
    int total = 0;

    for (int x = 0; x < len; x++)
    {
        for (int y = x + 1; y < len; y++)
        {
            if (arr[x] + arr[y] == value)
                total++;
        }
    }

    return total;
}
