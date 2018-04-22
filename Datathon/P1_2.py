MAXLOG = 10

Mi = (1 , 0 , 0 , 1)
M1 = (1 , 1 , 1 , 0)

memo = []

def Multiplication(A, B):
    return (A[0] * B[0] + A[1] * B[2], 
	A[0] * B[1] + A[1] * B[3], 
	A[2] * B[0] + A[3] * B[2], 
	A[2] * B[1] + A[3] * B[3])

def Pow(memo, n, i = 0):
    if(n == 0):
        return Mi
    m = Mi
    if((n&1)):
        m = memo[i]
    return Multiplication(m, Pow(memo, (n>>1), i + 1))
	
def initMemo(m, i):
    if(i == MAXLOG):
        return
    memo.append(m)
    initMemo(Multiplication(m, m), i+1)

def getExponent(n, m, memo, i):
    if(i == -1):
        return n
    n <<= 1
    temp = Multiplication(m, memo[i])
    if(temp[2] <= last):
        m = temp
        n |= 1
    return getExponent(n, m, memo, i-1)

def Fibonacci(last):
    initMemo(M1, 0)
    n = getExponent(0, Mi, memo, MAXLOG-1)
    m = Pow(memo, n-1)
    print(m[3], m[2])

if __name__ == '__main__':
    last = int(input())
    Fibonacci(last)