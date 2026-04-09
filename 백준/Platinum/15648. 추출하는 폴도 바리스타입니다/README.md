# [Platinum IV] 추출하는 폴도 바리스타입니다 - 15648 

[문제 링크](https://www.acmicpc.net/problem/15648) 

### 성능 요약

메모리: 29268 KB, 시간: 160 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 세그먼트 트리

### 제출 일자

2026년 4월 9일 11:00:02

### 문제 설명

<p>There is a sequence <em>S</em> with <em>N</em> numbers. You will make a subsequence of <em>S</em> that makes a harmony.</p>

<p>A sequence <em>A</em> makes a harmony if for every <em>i</em> greater than or equal to than 2, <em>A</em><sub><em>i</em> - 1</sub> ≡ <em>A</em><sub><em>i</em></sub> (<em>mod</em> <em>k</em>) or <em>A</em><sub><em>i</em> - 1</sub> - <em>d</em> ≤ <em>A</em><sub><em>i</em></sub> ≤ <em>A</em><sub><em>i</em> - 1</sub> + <em>d</em>. Find the longest subsequence of <em>S</em> that makes a harmony.</p>

### 입력 

 <p><em>N</em>, <em>k</em> and <em>d</em> is given at the first line. (1 ≤ <em>N</em> ≤ 5 × 10<sup>5</sup>, 1 ≤ <em>k</em>, <em>d</em> ≤ 5 × 10<sup>5</sup>)</p>

<p>Array <em>S</em> is given with <em>N</em> numbers in the second line. (1 ≤ <em>S</em><sub><em>i</em></sub> ≤ 5 × 10<sup>5</sup>)</p>

### 출력 

 <p>Print the length of the longest subsequence of <em>S</em> that makes a harmony.</p>

