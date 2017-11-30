import time


def enumeration(A):


	max_subset = 0
	index_inicio = index_fim = 0

	for i in range(0,len(A) + 1):
		for j in range(i,len(A) + 1):
			soma = sum(A[i:j])
			if soma > max_subset:
				max_subset = soma
				index_inicio = i
                index_fim = j

	

	

	return max_subset

def gerarArray():
	f = open("../../../entradas.txt", "r")
	fw = open("Enumeration_Saida.txt","w")
	for line in f:
		if "n = " in line:
			print line
			fw.write(line)

			array = f.next().split('\n')
			array = array[0].split(' ')
			
			for i in range(0,len(array)):
				if array[i] == '':
					array.pop(i)
				
				else:
					array[i] = int(array[i])

			#print array

			milli_sec_start = int(round(time.time() * 1000))
			
			maxsub = enumeration(array)

			milli_sec_fim = int(round(time.time() * 1000))

			tempo = milli_sec_fim - milli_sec_start
			print "Tempo: " + str(tempo) + " ms"
			fw.write("Tempo: " + str(tempo) + " ms\n")

			print "\nMax Subarray: " + str(maxsub)
			fw.write("Max Subarray: " + str(enumeration(array)) + "\n")
			
			print "------------------------\n"
			fw.write("------------------------\n")
	
	f.close()
	fw.close()

	return 0

if __name__ == '__main__':
	A = [0,1,2,3,4,5]
	gerarArray()

	
