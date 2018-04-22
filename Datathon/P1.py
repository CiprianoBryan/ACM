class matriz:
	def __init__(self, a, b, c, d):
		self.a = a
		self.b = b
		self.c = c
		self.d = d

def Multiplication(A, B):
    a = A.a*B.a + A.b*B.c
    b = A.a*B.b + A.b*B.d
    c = A.c*B.a + A.d*B.c
    d = A.c*B.b + A.d*B.d
    return matriz( a , b , c , d )

Mi = matriz( 1 , 0 , 0 , 1 )
M1 = matriz( 1 , 1 , 1 , 0 )

def Pow(b , n):
	if( n == 0 ):
		return Mi
	if( n%2 == 1 ):
		return Multiplication(b, Pow(b, n - 1))
	b2 = Pow(b , n/2)
	return Multiplication(b2, b2)

def bynarySearch(l , r , last):
	if( l > r ):
		return r
	me = ( l + r )//2
	if( Pow( M1 , me ).a <= last ):
		l = me + 1
	else:
		r = me - 1
	return bynarySearch(l, r, last)

def Fibonacci(last):
	n = bynarySearch(0, 80, last)
	M = Pow(M1, n)
	print(M.b, M.d)

if __name__ == '__main__':
    last = int(input())
    Fibonacci(last)