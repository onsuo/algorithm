/* 
 * 수 정렬하기 2 (https://www.acmicpc.net/problem/2751)
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * -입력-
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 
 * 둘째 줄부터 N개의 줄에는 수가 주어진다. 
 * 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 
 * 수는 중복되지 않는다.
 * 
 * -출력-
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int heap[1000000];
    for (int i = 0 ; i < N ; i++) {
        std::cin >> heap[i];
    }
    
    for (int leaf = 1 ; leaf < N ; leaf++) {
        int tleaf = leaf;
		for (int root ; tleaf != 0 ; tleaf = root) {
			root = (tleaf - 1) / 2;
			if (heap[root] < heap[tleaf]) {
				int temp = heap[root];
				heap[root] = heap[tleaf];
				heap[tleaf] = temp;
			}
		}
	}
    for (int last = N - 1 ; last > 0 ; last--) {
        int temp = heap[0];
        heap[0] = heap[last];
        heap[last] = temp;
        for (int root = 0, leaf = 1 ; leaf < last ; root = leaf) {
            leaf = 2 * root + 1;
            if (leaf + 1 < last && heap[leaf + 1] > heap[leaf]) {
                leaf++;
            }
            if (leaf < last && heap[root] < heap[leaf]) {
                int temp = heap[root];
                heap[root] = heap[leaf];
                heap[leaf] = temp;
            }
        }
    }

    for (int i = 0 ; i < N ; i++) {
        std::cout << heap[i] << "\n";
    }
}