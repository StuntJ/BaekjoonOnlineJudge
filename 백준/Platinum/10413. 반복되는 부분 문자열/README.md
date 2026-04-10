# [Platinum II] 반복되는 부분 문자열 - 10413 

[문제 링크](https://www.acmicpc.net/problem/10413) 

### 성능 요약

메모리: 5228 KB, 시간: 152 ms

### 분류

문자열, 접미사 배열과 LCP 배열

### 제출 일자

2026년 4월 10일 14:01:37

### 문제 설명

<p>String analysis often arises in applications from biology and chemistry, such as the study of DNA and protein molecules. One interesting problem is to find how many substrings are repeated (at least twice) in a long string.</p>

<p>In this problem, you will write a program to find the total number of repeated substrings in a string of at most 100 000 alphabetic characters. Any unique substring that occurs more than once is counted. As an example, if the string is “aabaab”, there are 5 repeated substrings: “a”, “aa”, “aab”, “ab”, “b”. If the string is “aaaaa”, the repeated substrings are “a”, “aa”, “aaa”, “aaaa”. Note that repeated occurrences of a substring may overlap (e.g. “aaaa” in the second case).</p>

### 입력 

 <p>The input consists of at most 10 cases. The first line contains a positive integer, specifying the number of cases to follow. Each of the following line contains a nonempty string of up to 100 000 alphabetic characters.</p>

### 출력 

 <p>For each line of input, output one line containing the number of unique substrings that are repeated. You may assume that the correct answer fits in a signed 32-bit integer.</p>

