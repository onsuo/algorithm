/* 
 * 0(2^0-1)
 * 1(2^1-1) 2(2^1)
 * 3(2^2-1) 4(2^2) 5(2^2+1) 6(2^2+2)
 * 7(2^3-1) 8(2^3) 9(2^3+1) 10(2^3+2) 11(2^3+3) 12(2^3+4) 13(2^3+5) 14(2^3+6)
 * ...
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
    
    // solution 1 : 최고위 root 로 최댓값 가져오기 -- 느림
    for (int last = N - 1 ; last > 0 ; last--) {
        // 최댓값을 최고위 root 로 가져옴
        for (int root = (last + 1) / 2 - 1 ; root >= 0 ; root--) {
            int leaf = 2 * root + 1;

            // solution 1-1
            int max = leaf == last ? heap[leaf] : std::max(heap[leaf], heap[leaf + 1]);
            int maxIndex = max == heap[leaf] ? 0 : 1;
            if (heap[root] < max) {
                int temp = heap[root];
                heap[root] = heap[leaf + maxIndex];
                heap[leaf + maxIndex] = temp;
            }
            // solution 1-2
            if (heap[leaf + 1] > heap[leaf] && leaf + 1 < last) {
                leaf++;
            }
            if (heap[root] < heap[leaf] && leaf != last) {
                int temp = heap[root];
                heap[root] = heap[leaf];
                heap[leaf] = temp;
            }
        }
        int temp = heap[0];
        heap[0] = heap[last];
        heap[last] = temp;
    }

    std::cout << "{ ";
    for (int i = 0 ; i < N ; i++) {
        std::cout << heap[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";

    // solution 2 : maximum heap 만들고 이용하기 -- 빠름
    // maximum heap (upstream), 초기 형성
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
        // maximum heap (downstream), 이전의 붕괴된 maximum heap 을 교정하여 새로운 maximum heap 형성
        for (int root = 0, leaf = 1 ; leaf < last ; root = leaf) {
            leaf = 2 * root + 1;
            if (leaf + 1 < last && heap[leaf + 1] > heap[leaf]) { // OutOfBound 유발 가능
                leaf++;
            }
            if (leaf < last && heap[root] < heap[leaf]) {
                int temp = heap[root];
                heap[root] = heap[leaf];
                heap[leaf] = temp;
            }
        }
    }

    std::cout << "{ ";
    for (int i = 0 ; i < N ; i++) {
        std::cout << heap[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}