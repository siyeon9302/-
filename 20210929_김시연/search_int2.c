// 4. 숫자 배열을 오름차순으로 정렬하고 검색할 숫자를 검색해서 배열내 위치를 출력하기
#include <stdio.h>

// 오름차순 정렬 함수 (버블 정렬 사용)
void sort_ascending(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 값 교환 (swap)
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 배열에서 특정 숫자의 위치를 찾는 함수 (여러 개가 있을 경우 첫 번째 위치)
int search_number(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return i;  // 숫자의 위치 반환
        }
    }
    return -1;  // 숫자를 찾지 못한 경우
}

int main() {
    // 숫자 배열
    int num[] = {-12, 7, 3, -8, 15, -3, 0, 10, -15, 5, -7, 12, 1, -1, 8, -4, 6, -2, 
                 9, 14, -6, 11, -9, 4, 13, 2, -5, -10, -11, -14, -13, 7, -8, 3, 0, 10, 
                 -15, 5, -7, 12};
    int size = sizeof(num) / sizeof(num[0]);  // 배열의 크기

    // 오름차순 정렬
    sort_ascending(num, size);

    // 정렬된 배열 출력
    printf("오름차순으로 정렬한 배열:");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    // 검색할 숫자
    int search_values[] = {-5, 12};
    int search_size = sizeof(search_values) / sizeof(search_values[0]);

    // 각각의 숫자 검색
    for (int i = 0; i < search_size; i++) {
        int index = search_number(num, size, search_values[i]);
        if (index != -1) {
            printf("검색한 숫자 %d의 배열 내 위치는 %d번째에 있습니다.\n", search_values[i], index);
        } else {
            printf("숫자 %d는 배열에 없습니다.\n", search_values[i]);
        }
    }

    return 0;
}
