import sys
import time
content = []

def selectionSort(array):
    startTime = time.time()
    n = len(array)
    
    for i in range(n):
        lowestIndex = i
        lowest = array[lowestIndex]
        for j in range(i+1, n):
            if array[j] < lowest:
                lowest = array[j]
                lowestIndex = j
                
        if lowest != array[i]:
            aux = array[i]
            array[i] = lowest
            array[lowestIndex] = aux
    
    endTime = time.time()
    totalTime = (endTime - startTime) * 10**3
    
    return array, totalTime
    
def insertionSort(array):
    startTime = time.time()
    n = len(array)
    
    for i in range(1, n):
        pivot = array[i]
        j = i - 1
        
        while j >= 0 and pivot < array[j]:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = pivot
    
    endTime = time.time()
    totalTime = (endTime - startTime) * 10**3
    
    return array, totalTime

def removerPrimeiro(vetor):
    content.reverse()
    content.pop()
    content.reverse()

with open(sys.argv[1], "r") as f:
    for line in f:
        content.append(int(line.split("\n")[0]))

removerPrimeiro(content)

print("Select an option:")
print("(1) Selection Sort\n(2) Insertion Sort\n(3) Compare times\n")
resposta = int(input())

if resposta == 1:
    selectionSorted, totalTime = selectionSort(content)
    print("\nSorted array:")
    print(selectionSorted)
    print("\nExecution time: ", totalTime, "ms")
elif resposta == 2:
    insertionSorted, totalTime = insertionSort(content)
    print("\nSorted array:")
    print(insertionSorted)
    print("\nExecution time: ", totalTime, "ms")
elif resposta == 3:
    selectionVector = content.copy()
    insertionVector = content.copy()
    selectionSorted, selectionTime = selectionSort(selectionVector)
    insertionTime, insertionTime = insertionSort(insertionVector)
    print("\nSelection Sort: ", selectionTime, "ms")
    print("Insertion Sort: ", insertionTime, "ms")