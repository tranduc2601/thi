#include<stdio.h>
int main(){
	int arr[maxSize], n = 0;
    int choice;
	int f = sizeof(arr) / sizeof(arr[0]);
    int value, found = 0;
	int n, i, N;
	printf("\t\tMENU\n1. Nhap so phan tu va gia tri cho mang.\n2. In ra gia tri cac phan tu trong mang.\n3. Dem so luong cac so nguyen tu co trong mang.\n4. Tim gia tri nho thu 2 trong mang.\n5. Them mot phan tu vao vi tri ngau nhien trong  mang.\n6. Xoa phan tu tai mot vi tri cu the (nguoi dung nhap vi tri).\n7. Sap xep mang theo thu tu giam dan (Insertion sort).\n8. Cho nguoi dùng nhap vao mot phan tu, tim kiem xem phan tu do co ton tai trong mang hay khong (Binary search).\n9. Xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat co o trong mang.\n10.Dao nguoc thu tu cua cac phan tu co trong mang.\n ");
	printf("moi ban chon chuc nang (1->10):"); scanf("%d",&N);
	switch (N){
		case 1:
			{
			printf(" nhap so phan tu cua mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf(" nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
			}
			break;
    	case 2:
    		{
    			for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
			}
			break;

    }
		case 3:
			{
				int primeCount = 0;
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) primeCount++;
                }
                printf(" so luong phan tu co trong mang: %d\n", primeCount);
				}
				
			}
			break;
		case 4 :
			{
				if (n < 2) {
                    printf(" tim phan tu thu 2.\n");
                } else {
                    int min_1 = intMax, min_2 = intMax;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] < min_1) {
                            min_2 = min_1;
                            min_1 = arr[i];
                        } else if (arr[i] > min_1 && arr[i] < min_2) {
                            min_2 = arr[i];
                        }
                    }
                    if (min_2 == intMax) {
                        printf("k co gia tri thu 2.\n");
                    } else {
                        printf(" gia tri nho thu 2 trong mang la: %d\n", min_2);
                    }
			}
			break;
		case 5:
			{
				int value, position;
                printf("nhap gia tri can them: ");
                scanf("%d", &value);
                printf("nhap vi tri can them: ");
                scanf("%d", &position);
                if (position >= 0 && position <= n && n < maxSize) {
                    for (int i = n; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    n++;
                    printf("mang sau khi them ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("vi tri khong hop le hoac mang k the chua them phan tu\n");
                }
			}
			break;
		case 6:
			{
				int position;
                printf(" nhap gia tri can xoa (0-based index): ");
                scanf("%d", &position);
                if (position >= 0 && position < n) {
                    for (int i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf(" mang sau khi xoa: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf(" vi tri khong dung\n");
                }
			}
			break;
		case 7:
			{
			for (i = 1; i < n; i++) {
        		key = arr[i];
        		j = i - 1;
        		while (j >= 0 && arr[j] > key) {
            		arr[j] = arr[j+1];
            		j--;
        	}	
        		arr[j] = key;
    	}
    		printf(" mang sau khi giam dan (insert sort) la: \n");
    		for (i = 0; i < n; i++) {
        	printf("%d ", arr[i]);
    }
			}
			break;
		case 8:
			{
			printf(" nhap so can tim: ");
    		scanf("%d", &value);
    		for (int i = 0; i < f; i++) {
        		if (arr[i] == value) {
            	printf(" vi tri cua so do la %d \n", i);
            	found = 1;
            	break;
        	}
    	}
    		if (!found) {
        	printf(" so khong ton tai trong mang \n");
    }
			}
			break;
		case 9:
			{
			}
			break;
		case 10:
			{
			}
			break;							
			
	return 0;
}
