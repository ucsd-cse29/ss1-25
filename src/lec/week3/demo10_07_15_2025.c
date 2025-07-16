#include <stdio.h>
#include <stdlib.h>

int *reverse(int arr[], int n) {
	int reversed[n]; // local variable bad??
	for (int i = 0; i < n; i++) {
		reversed[i] = arr[n - i - 1];
	}
	int *to_return = reversed;
	return to_return;
}

int *reverse_fix(int arr[], int n) {
	int *reversed = malloc(n * sizeof(int)); // heap!!
	if (reversed == NULL) {
		printf("Memory alloc failed!\n");
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		reversed[i] = arr[n - i - 1];
	}
	int *to_return = reversed;
	return to_return;
}

int main() {
	int arr[3] = {10, 20, 30};
	int *reversed = reverse(arr, 3);
	int arr1[3] = {8, 9, 10};
	int *reversed1 = reverse(arr1, 3);
	for (int i = 0 ; i < 3; i++) {
		printf("%d\n", reversed[i]); // undefined behavior
	}
	for (int i = 0 ; i < 3; i++) {
		printf("%d\n", reversed1[i]); // undefined behavior
	}
	// reverse fix! with malloc()
	printf("Reversing with malloc!\n");
	int *reversed_fix = reverse_fix(arr, 3);
	int *reversed_fix1 = reverse_fix(arr1, 3);
	for (int i = 0 ; i < 3; i++) {
		printf("%d\n", reversed_fix[i]); // undefined behavior
	}
	for (int i = 0 ; i < 3; i++) {
		printf("%d\n", reversed_fix1[i]); // undefined behavior
	}
	free(reversed_fix);
	free(reversed_fix1);
	// int *ptr = NULL;
	// printf("%d\n", *ptr);
}



