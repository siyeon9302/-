//숫자 배열을 내림차순으로 정렬하고 검색할 숫자를 검색해서 배열내 위치를 출력하기
#include <stdio.h>

// 배열 내 중복을 제거하는 함수
int remove_duplicates(int arr[], int size) {
    int temp[size]; // 임시 배열
    int new_size = 0; // 새로운 배열의 크기
    
    // 중복 없이 값을 새로운 배열에 추가
    for (int i = 0; i < size; i++) {
        int duplicate = 0;
        for (int j = 0; j < new_size; j++) {
            if (arr[i] == temp[j]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            temp[new_size++] = arr[i];
        }
    }
    
    // 원본 배열에 중복 없는 배열 복사
    for (int i = 0; i < new_size; i++) {
        arr[i] = temp[i];
    }
    
    return new_size; // 중복 제거 후 새로운 배열의 크기 반환
}

// 내림차순 정렬 함수 (버블 정렬)
void sort_descending(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                // 값 교환 (swap)
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 배열에서 특정 숫자의 위치를 찾는 함수
int search_number(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return i; // 숫자의 위치 반환
        }
    }
    return -1; // 찾지 못하면 -1 반환
}

int main() {
    // 숫자 배열
    int num[] = {5, 12, 18, 7, 25, 3, 14, 9, 21, 30, 2, 17, 6, 11, 20, 4, 13, 8, 19, 
                 26, 1, 15, 10, 22, 27, 24, 28, 23, 16, 29, 5, 12, 18, 7, 25, 3};
    int size = sizeof(num) / sizeof(num[0]); // 배열의 크기
    
    // 중복 제거
    size = remove_duplicates(num, size);
    
    // 내림차순 정렬
    sort_descending(num, size);
    
    // 정렬된 배열 출력
    printf("내림차순으로 정렬한 배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    
    // 검색할 숫자
    int search_values[] = {5, 25};
    int search_size = sizeof(search_values) / sizeof(search_values[0]);
    
    // 각각의 숫자 검색
    for (int i = 0; i < search_size; i++) {
        int index = search_number(num, size, search_values[i]);
        if (index != -1) {
            printf("검색한 숫자%d의 배열 내 위치는 %d번째입니다.\n", search_values[i], index);
        } else {
            printf("숫자 %d는 배열에 없습니다.\n", search_values[i]);
        }
    }

    return 0;
}
