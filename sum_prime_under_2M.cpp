#include <iostream>
#include <vector>

using namespace std;

int main() {
    int limit = 2000000;
    // 소수 여부를 체크할 배열 (true로 초기화)
    vector<bool> is_prime(limit + 1, true);
    
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    // 에라토스테네스의 체 알고리즘
    for (int p = 2; p * p <= limit; p++) {
        // p가 소수라면 p의 배수들을 모두 false로 변경
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                is_prime[i] = false;
        }
    }

    long long sum = 0; // 합계는 큰 범위인 long long 사용
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            sum += p;
        }
    }

    cout << "2,000,000 이하 소수의 합: " << sum << endl;

    return 0;
}
