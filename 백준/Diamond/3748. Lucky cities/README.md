# [Diamond V] Lucky cities - 3748 

[문제 링크](https://www.acmicpc.net/problem/3748) 

### 성능 요약

메모리: 38040 KB, 시간: 400 ms

### 분류

단절점과 단절선, 이중 연결 요소, 그래프 이론

### 제출 일자

2025년 1월 9일 22:22:12

### 문제 설명

<p>John has recently arrived in Romania for the South Eastern European Regional competitions. John has never been to Romania before so Romanians decided to organize sightseeing tour for him. This tour will include several Romanian cities and none of them will be visited more than once. John will start in one city and will visit some other cities according to a guide tour. At the end of the tour John will return to the starting point.</p>

<p>There are N cities numbered from 1 to N and M two-way roads in the country. Each road connects two different cities. Consider a sightseeing tour for John c<sub>1</sub>,c<sub>2</sub>, ...,c<sub>n</sub>, where each c<sub>i</sub> denotes a city in Romania. Then all c<sub>i</sub> must be distinct, c<sub>i</sub> and c<sub>i+1</sub> must be connected by a road, where i=1,2,...,n-1, c<sub>n</sub> and c<sub>1</sub> must be connected by a road as well.</p>

<p>Being a odd person John would like to visit an odd number of cities. The organizers have drawn the plan of all possible tours with an odd number of cities.</p>

<p>Residents of the cities would like John to visit them. So if there is at least one tour passing through some city than this city is called lucky. Your task is to calculate the number of lucky cities in Romania.</p>

### 입력 

 <p>The first line of input contains a single integer T – a number of test cases. Every test case starts with a line containing two integers separated by a single space – N and M. Each of the next M lines will contain two integers a<sub>i</sub> and b<sub>i</sub> separated by a single space – the labels of cities that i-th road connects.</p>

<p>Constrains:</p>

<ul>
	<li>1 ≤ T ≤ 77,</li>
	<li>0 ≤ N, M ≤ 100000 (10<sup>5</sup>),</li>
	<li>1 ≤ a<sub>i</sub> < b<sub>i</sub> ≤ N. </li>
</ul>

### 출력 

 <p>Output should contain T lines – answers for each of the test cases.</p>

