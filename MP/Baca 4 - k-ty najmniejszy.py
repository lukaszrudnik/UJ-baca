# Lukasz Rudnik

def kthSmallest(arr, l, r, k):
    if k > 0 and k <= r - l + 1:
        
        n = r - l + 1
        

        medianPos = l
        i = l
        while i + 4 <= r:
    
            groupStart = i
            groupEnd = i + 4
            for j in range(groupStart, groupEnd):
                for m in range(groupStart, groupEnd - (j - groupStart)):
                    if arr[m] > arr[m+1]:
                        arr[m], arr[m+1] = arr[m+1], arr[m]
          
            median = groupStart + 2
            arr[median], arr[medianPos] = arr[medianPos], arr[median]
            medianPos += 1
            i += 5
        
       
        if i <= r:
            groupStart = i
            groupEnd = r
            groupSize = groupEnd - groupStart + 1
          
            for j in range(groupStart, groupEnd):
                for m in range(groupStart, groupEnd - (j - groupStart)):
                    if arr[m] > arr[m+1]:
                        arr[m], arr[m+1] = arr[m+1], arr[m]
          
            median = groupStart + (groupSize - 1) // 2
            arr[median], arr[medianPos] = arr[medianPos], arr[median]
            medianPos += 1
        
      
        numMedians = medianPos - l
        
        
        if numMedians == 1:
            pivot = arr[l]
        else:
            pivot = kthSmallest(arr, l, medianPos - 1, (numMedians + 1) // 2)
        
     
        pos = partition(arr, l, r, pivot)
        
       
        if pos - l == k - 1:
            return arr[pos]
        elif pos - l > k - 1:
            return kthSmallest(arr, l, pos - 1, k)
        else:
            return kthSmallest(arr, pos + 1, r, k - (pos - l + 1))
    
    return float('inf')

def partition(arr, l, r, pivot):
    
    pivotPos = l
    while pivotPos <= r:
        if arr[pivotPos] == pivot:
            break
        pivotPos += 1
    arr[pivotPos], arr[r] = arr[r], arr[pivotPos]
    

    i = l
    for j in range(l, r):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    
    arr[i], arr[r] = arr[r], arr[i]
    return i


def findKthSmallest(arr, k):
    return kthSmallest(arr, 0, len(arr) - 1, k)




def main():
    z = int(raw_input())
    for _ in range(z):

        n = int(raw_input())
        arr = list(map(int, raw_input().split()))
        m = int(raw_input())
        queries = list(map(int, raw_input().split()))
        
        for k in queries:
            if 1 <= k <= n:
                print "%d %d" % (k, findKthSmallest(arr, k))
            else:
                print "%d brak" % k

if __name__ == "__main__":
    main()