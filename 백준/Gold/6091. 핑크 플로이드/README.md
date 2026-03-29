# [Gold I] 핑크 플로이드 - 6091 

[문제 링크](https://www.acmicpc.net/problem/6091) 

### 성능 요약

메모리: 6268 KB, 시간: 56 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2026년 3월 29일 15:27:33

### 문제 설명

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/6091/1.png" style="float:right; height:121px; width:262px">The young programmers Peter and Stancho were hired by two cosmic agencies. The agency of Peter designed a new cosmic station, composed of N modules, labeled from 1 to N. Some couples of different modules are linked by corridors in such way that it is possible to go from each module to each other module by unique path of corridors (see the Figure). The length of each of the corridors is positive integer. There is no more then one corridor that links two modules. The chiefs of Peter would like to keep in secret the project. That is why Peter encoded the topology of the station giving for each two modules the distance between them (i.e. the sum of the lengths of the corridors on the unique path between the modules).</p>

<p>Now Stancho has a difficult task – he promised to his bosses to decrypt the coding of Peter and to reconstruct the topology of the station. Unfortunately, Stancho is not experienced enough. Help him. Write a program recon that solves the task.</p>

### 입력 

 <p>The first line of the standard input contains the number N of the modules (3 ≤ N ≤ 1024). Then N – 1 lines follow. On the first of these lines the distances from module 1 to modules 2, 3,…, N are given, separated by single spaces. On the second line re given, separated by single spaces also, the distances from module 2 to modules 3, 4,…, N, and so on. The last line contains only the distance from module N – 1 to module N. All distances are positive integers not greater than 1024.</p>

### 출력 

 <p>The program has to print N lines to the standard output. The first line has to contain the list of the neighbors of module 1, i.e. the modules that are linked with corridors to it. The list has to start with the number L of neighbors followed by their labels, sorted in increasing order. All numbers has to be separated by single spaces. On the second row of the output, formatted in the same way, the list of the neighbors of module 2 has to be printed, and so on. The output has to finish with the list of the neighbors of module N.</p>

