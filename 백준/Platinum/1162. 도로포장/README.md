# [Platinum V] 도로포장 - 1162 

[문제 링크](https://www.acmicpc.net/problem/1162) 

### 성능 요약

메모리: 8296 KB, 시간: 72 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2026년 3월 27일 00:54:34

### 문제 설명

<p>Farmer John dutifully checks on the cows every day. He traverses some of the M (1 <= M <= 50,000) trails conveniently numbered 1..M from pasture 1 all the way out to pasture N (a journey which is always possible for trail maps given in the test data). The N (1 <= N <= 10,000) pastures conveniently numbered 1..N on Farmer John's farm are currently connected by bidirectional dirt trails.  Each trail i connects pastures P1_i and P2_i (1 <= P1_i <= N; 1 <= P2_i <= N) and requires T_i (1 <= T_i <= 1,000,000) units of time to traverse.</p>

<p>He wants to revamp some of the trails on his farm to save time on his long journey. Specifically, he will choose K (1 <= K <= 20) trails to turn into highways, which will effectively reduce the trail's traversal time to 0. Help FJ decide which trails to revamp to minimize the resulting time of getting from pasture 1 to N.</p>

### 입력 

 <p>* Line 1: Three space-separated integers: N, M, and K</p>

<p>* Lines 2..M+1: Line i+1 describes trail i with three space-separated integers: P1_i, P2_i, and T_i</p>

### 출력 

 <p>* Line 1: The length of the shortest path after revamping no more than K edges</p>

