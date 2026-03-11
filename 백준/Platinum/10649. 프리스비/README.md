# [Platinum V] 프리스비 - 10649 

[문제 링크](https://www.acmicpc.net/problem/10649) 

### 성능 요약

메모리: 2024 KB, 시간: 376 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2026년 3월 11일 16:15:28

### 문제 설명

<p>Farmer John and his herd are playing frisbee.  Bessie throws the frisbee down the field, but it's going straight to Mark the field hand on the other team!  Mark has height H (1 <= H <= 1,000,000,000), but there are N cows on Bessie's team gathered around Mark (2 <= N <= 20). They can only catch the frisbee if they can stack up to be at least as high as Mark.  Each of the N cows has a height, weight, and strength. A cow's strength indicates the maximum amount of total weight of the cows that can be stacked above her.  </p>

<p>Given these constraints, Bessie wants to know if it is possible for her team to build a tall enough stack to catch the frisbee, and if so, what is the maximum safety factor of such a stack.  The safety factor of a stack is the amount of weight that can be added to the top of the stack without exceeding any cow's strength.</p>

### 입력 

 <p>The first line of input contains N and H.</p>

<p>The next N lines of input each describe a cow, giving its height, weight, and strength.  All are positive integers at most 1 billion.</p>

### 출력 

 <p>If Bessie's team can build a stack tall enough to catch the frisbee, please output the maximum achievable safety factor for such a stack. Otherwise output "Mark is too tall" (without the quotes).</p>

