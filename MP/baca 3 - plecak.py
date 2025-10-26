# Lukasz Rudnik

def knapsack(W, val, wt):
    
    # Initializing dp list
    dp = [0] * (W + 1)
    dpCount = [0] * (W + 1)

    # Taking first i elements
    for i in range(1, len(wt) + 1):
        
        # Starting from back, so that we also have data of
        # previous computation of i-1 items
        for j in range(W, wt[i - 1] - 1, -1):
            newVal = dp[j - wt[i - 1]] + val[i - 1]
            newCount = dpCount[j - wt[i - 1]] + 1
            if newVal > dp[j] or ( newVal == dp[j] and newCount > dpCount[j] ): 
                dp[j]=newVal
                dpCount[j]=newCount
    
    return dp[W]



# main
L = int(raw_input())
for _ in range(L):
    line = raw_input().strip()
    numbers = list(map(int, line.split())) 
    
    M = numbers[0]
    values = []
    weights = []
    
    for i in range(1, len(numbers), 2):
        v = numbers[i]
        w = numbers[i + 1]
        values.append(v)
        weights.append(w)
    
    print knapsack(M, values, weights)
