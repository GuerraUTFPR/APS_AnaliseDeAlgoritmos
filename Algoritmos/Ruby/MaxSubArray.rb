# Reference Enumeration: https://pt.wikipedia.org/wiki/Sublista_cont%C3%ADgua_de_soma_m%C3%A1xima 
# Reference Dynamic Algorithm: https://github.com/devlinjunker/courses-max-subarray/blob/master/max-sub.py
# Reference Div and Conquer Algorithm: Dhawal Patel - Programming forum

# Código adaptado para Ruby por: Matheus Guerra

####################################################
def enumeration(arr)
  max_ate_agora = 0
  n = arr.size
  for l in 1..n
    for u in l..n
      soma = 0
      for i in l..u              	       	
        soma = soma + arr[i - 1]
      end
      max_ate_agora = [max_ate_agora, soma].max
    end
  end

  return max_ate_agora
end
####################################################


def betterEnumeration(arr)
    max_ate_agora = 0
    n = arr.size
    for l in 1..n
        soma = 0
        for u in l..n
            soma = soma + arr[u - 1]
            max_ate_agora = [max_ate_agora, soma].max
        end
    end
    return max_ate_agora
end
####################################################

INFINITY = 99999999999999999

def CrossingSum(arr,l,m,h)
    summ = 0
    left_sum = -INFINITY
    for i in (m).downto(l-1)
            summ = summ + arr[i]
            if summ > left_sum
                    left_sum = summ
            end
    end
    summ = 0
    right_sum = -INFINITY
    for i in m+1..h
            summ = summ + arr[i]
            if summ > right_sum
                    right_sum = summ
            end
    end

    return left_sum + right_sum
end


def divAndConquer(arr,l,h)
    if l ==  h 
      return arr[l]
    end

    mid = (l+h)/2    
    mid = mid.floor    
    maximum = [divAndConquer(arr,l,mid), divAndConquer(arr,mid+1,h), CrossingSum(arr,l,mid,h)].max

    return maximum
end

####################################################


def dynamic(arr)
     
    max_so_far = 0
    max_ending_here = 0
     
    for i in 0..arr.size-1
        max_ending_here = max_ending_here + arr[i]
        if max_ending_here < 0
            max_ending_here = 0             
         
        elsif max_so_far < max_ending_here
            max_so_far = max_ending_here
        end
    end
             
    return max_so_far
end



####################################################






arq = File.open("../../entradas.txt")
output = File.new("saida.txt", "w")
array = Array.new
asn = 0
n = 0

	arq.each_line do |line|
  		if line[0] == "n"
        n = line	 	
  		end

  		if line[0] != "n" and line[0] != "\n"
  			array = line.split(' ')
  			array = array.collect{|s| s.to_i}        
        
        puts n
        output.puts n

        #========================= Enumeration ========================
        t1 = Time.now
  			ans = enumeration(array)
        t2 = Time.now
        puts "Enumeration:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        output.puts "Enumeration:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        #========================= End Enumeration =====================

        
        puts "\n"
        output.puts "\n"
        #========================= Better Enumeration ==================
        t1 = Time.now
        ans = betterEnumeration(array)
        t2 = Time.now
        puts "Better Enumeration:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        output.puts "Better Enumeration:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        #========================= End Better Enumeration ==============

        
        puts "\n"
        output.puts "\n"
        #========================= Divide and Conquer ==================
        t1 = Time.now
        ans = divAndConquer(array,0,(array.size)-1)
        t2 = Time.now
        puts "Divide and Conquer:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        output.puts "Divide and Conquer:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        #========================= End Divide and Conquer ==============
        

        puts "\n"
        output.puts "\n"
        #========================= Dynamic =============================
        t1 = Time.now
        ans = dynamic(array)
        t2 = Time.now
        puts "Dynamic:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        output.puts "Dynamic:\nMaxSubArray = #{ans}\nTempo gasto = #{(t2-t1)*1000} ms\n"
        #========================= End Dynamic =============================

        puts "=============================="
        puts "\n"
        output.puts "=============================="
        output.puts "\n"


  		end 		

	end

arq.close