# Reference Enumeration: https://pt.wikipedia.org/wiki/Sublista_cont%C3%ADgua_de_soma_m%C3%A1xima 
# Reference Dynamic Algorithm: https://github.com/devlinjunker/courses-max-subarray/blob/master/max-sub.py
# Reference Div and Conquer Algorithm: Dhawal Patel - Programming forum

import time
import sys

####################################################
def enumeration(A):
    max_ate_agora = 0
    N = len(A)
    for L in range(1, N + 1):
        for U in range(L, N + 1):
            soma = 0
            for I in range(L, U + 1):
                soma = soma + A[I - 1]
            max_ate_agora = max(max_ate_agora, soma)
    return max_ate_agora

####################################################
def betterEnumeration(A):
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
####################################################
def CrossingSum(arr,l,m,h):
    summ = 0
    left_sum = -sys.maxint
    for i in range(m,l-1,-1):
            summ = summ + arr[i]
            if summ > left_sum:
                    left_sum = summ

    summ = 0
    right_sum = -sys.maxint
    for i in range(m+1,h+1):
            summ = summ + arr[i]
            if summ > right_sum:
                    right_sum = summ

    return left_sum + right_sum

def Divide(arr,l,h):
    if l ==  h :
            return arr[l]
    mid = (l+h)//2
    maximum = max(Divide(arr,l,mid) , Divide(arr,mid+1,h) , CrossingSum(arr,l,mid,h))

    return maximum

####################################################
def dynamic(A):
     
    max_so_far = 0
    max_ending_here = 0
     
    for i in range(0, len(A)):
        max_ending_here = max_ending_here + A[i]
        if max_ending_here < 0:
            max_ending_here = 0
         
        elif (max_so_far < max_ending_here):
            max_so_far = max_ending_here
             
    return max_so_far
####################################################


def gerarArray():
	f = open("../../entradas.txt", "r")
	fw = open("Python_Saidas.txt","w")
	for line in f:
		if "n = " in line:
			print "------------------------\n"
			fw.write("------------------------\n")
			print line
			fw.write(line)

			array = f.next().split('\n')
			array = array[0].split(' ')
			
			for i in range(0,len(array)):
				if array[i] == '':
					array.pop(i)
				
				else:
					array[i] = int(array[i])


			# -------------------------------------------- Enumeration
			print "Enumeration:"
			fw.write("\nEnumeration:")
			milli_sec_start = int(round(time.time() * 1000))
			maxsub = enumeration(array)
			milli_sec_fim = int(round(time.time() * 1000))
			tempo = milli_sec_fim - milli_sec_start
			
			print "Tempo: " + str(tempo) + " ms"
			fw.write("\nTempo: " + str(tempo) + " ms\n")

			print "Max Subarray: " + str(maxsub) + "\n"
			fw.write("Max Subarray: " + str(maxsub) + "\n")

			# -------------------------------------------- Better Enumeration
			print "BetterEnumeration:"
			fw.write("\nBetterEnumeration:")
			milli_sec_start = int(round(time.time() * 1000))
			maxsub = betterEnumeration(array)
			milli_sec_fim = int(round(time.time() * 1000))
			tempo = milli_sec_fim - milli_sec_start

			print "Tempo: " + str(tempo) + " ms"
			fw.write("\nTempo: " + str(tempo) + " ms\n")
			
			print "Max Subarray: " + str(maxsub) + "\n"
			fw.write("Max Subarray: " + str(maxsub) + "\n")
			# -------------------------------------------- Div and Conquer
			
			print "Div and Conquer:"
			fw.write("\nDiv and Conquer:")
			milli_sec_start = int(round(time.time() * 1000))
			maxsub = Divide(array,0,len(array)-1)
			milli_sec_fim = int(round(time.time() * 1000))
			tempo = milli_sec_fim - milli_sec_start
			
			print "Tempo: " + str(tempo) + " ms"
			fw.write("\nTempo: " + str(tempo) + " ms\n")

			print "Max Subarray: " + str(maxsub) + "\n"
			fw.write("Max Subarray: " + str(maxsub) + "\n")
			

			# --------------------------------------------- Dynamic
			print "Dynamic:"
			fw.write("\nDynamic: ")
			milli_sec_start = int(round(time.time() * 1000))
			
			maxsub = dynamic(array)

			milli_sec_fim = int(round(time.time() * 1000))

			tempo = milli_sec_fim - milli_sec_start

			print "Tempo: " + str(tempo) + " ms"
			fw.write("\nTempo: " + str(tempo) + " ms\n")
			
			print "Max Subarray: " + str(maxsub) + "\n"
			fw.write("Max Subarray: " + str(maxsub) + "\n")
			# ---------------------------------------------			

	
	f.close()
	fw.close()

	return 0

if __name__ == '__main__':
	A = [0,1,2,3,4,5]
	gerarArray()

	
