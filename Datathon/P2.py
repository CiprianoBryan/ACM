def InversaMatriz(M):
	for i in range(len(M)):
		for j in range(len(M)-i):
			M[ i ][ j ], M[ len(M) - j - 1 ][ len(M) - i - 1 ] = M[ len(M) - j - 1 ][ len(M) - i - 1 ], M[ i ][ j ]
	print(M)

if __name__ == '__main__':
	M = [[11, 12, 13, 14],
	[21, 22, 23, 24],
	[31, 32, 33, 34],
	[41, 42, 43, 44]]
	InversaMatriz( M )