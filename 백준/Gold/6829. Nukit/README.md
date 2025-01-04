# [Gold II] Nukit - 6829 

[문제 링크](https://www.acmicpc.net/problem/6829) 

### 성능 요약

메모리: 9236 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2024년 6월 6일 11:32:35

### 문제 설명

<p>Canada’s top two nuclear scientists, Patrick and Roland, have just completed the construction of the world’s first nuclear fission reactor. Now it is their job to sit and operate the reactor all day, every day. Naturally they got a little bored after doing this for a while and as a result, two things have happened. First, they can now control the individual reactions that happen inside the reactor. Second, to pass the time, they have invented a new game called Nukit.</p>

<p>At the beginning of Nukit, a number of particles are put in the reactor. The players take alternating turns, with Patrick always going first. When it is a player’s turn to move, they must select some of the remaining particles to form one of the possible reactions. Then those particles are destroyed. Eventually there will be so few particles that none of the reactions can be formed; at this point, the first person who is unable to form a reaction on their turn loses</p>

<p> In our universe you can assume that there are only 4 types of particles: A, B, C, D. Each reaction is a list of particles that can be destroyed on a single turn. The five reactions are:</p>

<ol>
	<li>AABDD</li>
	<li>ABCD</li>
	<li>CCD</li>
	<li>BBB</li>
	<li>AD</li>
</ol>

<p>For example, the first reaction “AABDD” says that it is allowable to destroy two A, one B, and two D particles all at the same time on a turn.</p>

<p>It turns out that, no matter how many particles start off in the reactor, exactly one of Patrick or Roland has a perfect winning strategy. By player X has a perfect winning strategy, we mean that no matter what the other player does, player X can always win by carefully choosing reactions. For example, if the reactor starts off with one A, five B, and three D particles then Roland has the following perfect winning strategy: “if Patrick forms reaction BBB initially, then form reaction AD afterward; if Patrick forms reaction AD initially, then form reaction BBB afterward.” (The strategy works because either way, on Patrick’s second turn, there are not enough particles left to form any reactions.)</p>

<p>Given the number of each type of particle initially in the reactor, can you figure out who has a perfect winning strategy?</p>

### 입력 

 <p>The first line of input contains n, the number of test cases (1 ≤ n < 100). Each test case consists of 4 integers separated by spaces on a single line; they represent the initial number of A, B, C and D particles. You can assume that there are initially between 0 and 8 (inclusive) of each type of particle.</p>

### 출력 

 <p>For each test case, output the player who has a perfect winning strategy, either “Roland” or “Patrick”.</p>

