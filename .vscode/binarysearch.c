#include<stdio.h>
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size]; 
printf("Enter the elements in sorted order:\n"); 
for (int i = 0; i < size; i++) {
printf("Enter element at index [%d]: ", i);
scanf("%d", &arr[i]);
}
int key;
printf("Enter element to find: ");
scanf("%d", &key );
int low = 0;
int high = size - 1;
int flag = 0;
while (low <= high) {
int mid = low + (high - low) / 2; 
if (arr[mid] == key ) {
printf("Element %d found at index [%d].\n",key, mid);
flag = 1;
break; 
} else if (arr[mid] < key) {
low = mid + 1; 
} else {
high = mid - 1; 
}
}
if (!flag) {
printf("Element %d not found in the array.\n",key);
}
return 0;
}