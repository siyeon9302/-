//문자 배열에서 검색할 단어 검색해서 단어의 배열내 위치와 개수 출력하기
#include <stdio.h>
#include <string.h>

// 검색할 단어
#define SEARCH_WORD "human"
#define WORD_LENGTH 5  // "human"의 길이

int main() {
    // 주어진 문자 배열
    char str[] = {'J','e','w','e','l',' ','K','i','t','e',' ','h','h','u','m','a','n',' ','L','a','d','d','e','r',' ','h','u','m','a','n',
    'h','u','m','a','n',' ','h','u','m','a','n','.',' ','M','i','r','r','o','r',' ','h','u','m','e','n',' ','N','e','e','d','l','e',' ','O','c','t','-',
    'o','p','u','s',' ','h','u','.','.','m','a','n',' ','P','e','n','c','i','l',' ','Q','u','i','l','t',' ','R','o','c','k','e','t',' ',
    'S','h','i','p',' ','h','u','m','a','n'};
    
    int strLength = sizeof(str) / sizeof(str[0]); // 배열의 길이
    int count = 0;  // "human" 단어의 개수를 셀 변수

    // 배열을 순차적으로 탐색
    for (int i = 0; i <= strLength - WORD_LENGTH; i++) {
        // "human" 단어의 첫 글자가 있으면 비교 시작
        if (strncmp(&str[i], SEARCH_WORD, WORD_LENGTH) == 0) {
            // "human" 다음이 배열의 끝이거나 공백인지 확인
            if (i + WORD_LENGTH == strLength || str[i + WORD_LENGTH] == ' ' || str[i + WORD_LENGTH] == '.') {
                printf("검색한 단어 \"%s\"의 배열 내 위치는 %d번째\n", SEARCH_WORD, i);
                count++;
            }
        }
    }

    // 결과 출력
    if (count > 0) {
        printf("검색한 단어 \"%s\"의 배열 내 개수는 %d번\n", SEARCH_WORD, count);
    } else {
        printf("\"%s\" 단어가 배열에서 발견되지 않았습니다.\n", SEARCH_WORD);
    }

    return 0;
}
