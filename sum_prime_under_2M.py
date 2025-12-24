import time

def sieve_of_eratosthenes(limit):
    primes = [True] * (limit + 1)
    primes[0] = primes[1] = False

    for number in range(2, int(limit**0.5) + 1):
        if primes[number]:
            for multiple in range(number * number, limit + 1, number):
                primes[multiple] = False

    return [i for i, is_prime in enumerate(primes) if is_prime]

# 1. 측정 시작 시간 기록
start_time = time.time()

limit = 2000000
primes = sieve_of_eratosthenes(limit)
result = sum(primes)

# 2. 측정 종료 시간 기록
end_time = time.time()

# 3. 결과 출력
print(f"2,000,000 이하 소수의 합: {result}")
print(f"수행 시간: {(end_time - start_time) * 1000:.2f} ms") # 밀리초 단위로 변환