#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// H�m ki?m tra s? nguy�n t?
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int arr[MAX_SIZE], n = 0;
    int choice;

    do {
        printf("\nMENU:\n");
        printf("1. Nh?p s? ph?n t? v� gi� tr? cho m?ng\n");
        printf("2. In ra gi� tr? c�c ph?n t? trong m?ng\n");
        printf("3. �?m s? lu?ng c�c s? nguy�n t? c� trong m?ng\n");
        printf("4. T�m gi� tr? nh? th? hai trong m?ng\n");
        printf("5. Th�m m?t ph?n t? v�o v? tr� ng?u nhi�n trong m?ng\n");
        printf("6. X�a ph?n t? t?i m?t v? tr� c? th?\n");
        printf("7. S?p x?p m?ng theo th? t? gi?m d?n (Insertion sort)\n");
        printf("8. T�m ki?m m?t ph?n t? trong m?ng (Binary search)\n");
        printf("9. X�a to�n b? ph?n t? tr�ng l?p v� hi?n th? c�c ph?n t? d?c nh?t\n");
        printf("10. �?o ngu?c th? t? c?a c�c ph?n t? trong m?ng\n");
        printf("0. Tho�t chuong tr�nh\n");
        printf("Nh?p l?a ch?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Tho�t chuong tr�nh.\n");
                break;

            case 1:
                printf("Nh?p s? ph?n t? c?a m?ng: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nh?p ph?n t? th? %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 3: {
                int prime_count = 0;
                for (int i = 0; i < n; i++) {
                    if (is_prime(arr[i])) prime_count++;
                }
                printf("S? lu?ng s? nguy�n t? trong m?ng: %d\n", prime_count);
                break;
            }

            case 4: {
                if (n < 2) {
                    printf("M?ng kh�ng d? ph?n t? d? t�m gi� tr? nh? th? hai.\n");
                } else {
                    int min1 = INT_MAX, min2 = INT_MAX;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] < min1) {
                            min2 = min1;
                            min1 = arr[i];
                        } else if (arr[i] > min1 && arr[i] < min2) {
                            min2 = arr[i];
                        }
                    }
                    if (min2 == INT_MAX) {
                        printf("Kh�ng t?n t?i gi� tr? nh? th? hai.\n");
                    } else {
                        printf("Gi� tr? nh? th? hai trong m?ng: %d\n", min2);
                    }
                }
                break;
            }

            case 5: {
                int value, position;
                printf("Nh?p gi� tr? c?n th�m: ");
                scanf("%d", &value);
                printf("Nh?p v? tr� c?n th�m (0-based index): ");
                scanf("%d", &position);
                if (position >= 0 && position <= n && n < MAX_SIZE) {
                    for (int i = n; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    n++;
                    printf("M?ng sau khi th�m: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("V? tr� kh�ng h?p l? ho?c m?ng d� d?y.\n");
                }
                break;
            }

            case 6: {
                int position;
                printf("Nh?p v? tr� c?n x�a (0-based index): ");
                scanf("%d", &position);
                if (position >= 0 && position < n) {
                    for (int i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("M?ng sau khi x�a: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("V? tr� kh�ng h?p l?.\n");
                }
                break;
            }

            case 7: {
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("M?ng sau khi s?p x?p gi?m d?n: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 8: {
                int value;
                printf("Nh?p gi� tr? c?n t�m: ");
                scanf("%d", &value);
                int left = 0, right = n - 1, mid;
                bool found = false;
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arr[mid] == value) {
                        found = true;
                        break;
                    } else if (arr[mid] < value) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (found) {
                    printf("Gi� tr? %d c� t?n t?i trong m?ng.\n", value);
                } else {
                    printf("Gi� tr? %d kh�ng t?n t?i trong m?ng.\n", value);
                }
                break;
            }

            case 9: {
                int unique[MAX_SIZE], unique_count = 0;
                for (int i = 0; i < n; i++) {
                    bool is_duplicate = false;
                    for (int j = 0; j < unique_count; j++) {
                        if (arr[i] == unique[j]) {
                            is_duplicate = true;
                            break;
                        }
                    }
                    if (!is_duplicate) {
                        unique[unique_count++] = arr[i];
                    }
                }
                n = unique_count;
                for (int i = 0; i < n; i++) {
                    arr[i] = unique[i];
                }
                printf("M?ng sau khi x�a ph?n t? tr�ng l?p: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 10: {
                for (int i = 0; i < n / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }
                printf("M?ng sau khi d?o ngu?c: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }

    } while (choice != 0);

    return 0;
}

