# [Platinum V] 안대 낀 스피드러너 - 14451 

[문제 링크](https://www.acmicpc.net/problem/14451) 

### 성능 요약

메모리: 14708 KB, 시간: 32 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 3월 19일 16:14:46

### 문제 설명

<p>Bessie has gotten herself stuck on the wrong side of Farmer John's barn again, and since her vision is so poor, she needs your help navigating across the barn.</p>

<p>The barn is described by an N×N grid of square cells (2≤N≤20), some being empty and some containing impassable haybales. Bessie starts in the lower-left corner (cell 1,1) and wants to move to the upper-right corner (cell N,N). You can guide her by telling her a sequence of instructions, each of which is either "forward", "turn left 90 degrees", or "turn right 90 degrees". You want to issue the shortest sequence of instructions that will guide her to her destination. If you instruct Bessie to move off the grid (i.e., into the barn wall) or into a haybale, she will not move and will skip to the next command in your sequence.</p>

<p>Unfortunately, Bessie doesn't know if she starts out facing up (towards cell 1,2) or right (towards cell 2,1). You need to give the shortest sequence of directions that will guide her to the goal regardless of which case is true. Once she reaches the goal she will ignore further commands.</p>

### 입력 

 <p>The first line of input contains N.</p>

<p>Each of the N following lines contains a string of exactly N characters, representing the barn. The first character of the last line is cell 1,1. The last character of the first line is cell N, N.</p>

<p>Each character will either be an H to represent a haybale or an E to represent an empty square.</p>

<p>It is guaranteed that cells 1,1 and N,N will be empty, and furthermore it is guaranteed that there is a path of empty squares from cell 1,1 to cell N,N.</p>

### 출력 

 <p>On a single line of output, output the length of the shortest sequence of directions that will guide Bessie to the goal, irrespective whether she starts facing up or right.</p>

<p> </p>

