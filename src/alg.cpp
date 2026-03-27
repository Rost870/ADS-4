// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int* arr, int len, int value) {
    int total = 0;

    for (int a = 0; a < len; a++) {
        for (int b = a + 1; b < len; b++) {
            if (arr[a] + arr[b] == value) {
                total++;
            }
        }
    }

    return total;
}

int countPairs2(int* arr, int len, int value) {
    int total = 0;

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;

        int pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                pos = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (pos != -1) {
            int k = pos;
            while (k < len && arr[k] == target) {
                total++;
                k++;
            }
        }
    }

    return total;
}

int countPairs3(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int total = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum < value) {
            left++;
        } else if (sum > value) {
            right--;
        } else {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                total += n * (n - 1) / 2;
                break;
            }

            int left_val = arr[left];
            int right_val = arr[right];

            int count_left = 0;
            int count_right = 0;

            while (left < right && arr[left] == left_val) {
                count_left++;
                left++;
            }

            while (right >= left && arr[right] == right_val) {
                count_right++;
                right--;
            }

            total += count_left * count_right;
        }
    }

    return total;
}
