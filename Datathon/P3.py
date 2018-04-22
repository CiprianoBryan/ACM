def orderAndUniques(v):
	v.sort()
	vUnique = []
	vUnique.append(v[0])
	for i in range(1, len(v)):
		if(v[i-1]!=v[i]):
			vUnique.append(v[i])
	return vUnique

if __name__ == '__main__':
	v = [ 10,8,1,1,3,6,2]
	res = orderAndUniques(v)
	print(res)