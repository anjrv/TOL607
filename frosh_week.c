#include <stdio.h>
#include <stdlib.h>

long long count;

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n1 && j < n2) {
    if (L[i] < M[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = M[j++];
      count += n1 - i;
    }
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = M[j++];
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()
{
    count = 0;
    int n;
    scanf("%d", &n);

    int students[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &students[i]);
    }

    mergeSort(students, 0, n - 1);
    printf("%lld\n", count);

    return 0;
}