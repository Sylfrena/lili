def merg_sort(a)
   return a if a.length <= 1
   
        q = a.length/2 
        merg_sort(a[0...q])
        merg_sort(a[q..-1])
        merge(a[0...q], a[q..-1])
end
    
def merge(la,ra)
    
    arr = []
    until la.empty? || ra.empty?   
        
        arr << (la.first <= ra.first ? la.shift : ra.shift )
    end
    arr + la + ra
    
end


a = [ 1,5,7,9,3, 4, 8, 40]
p merg_sort(a)