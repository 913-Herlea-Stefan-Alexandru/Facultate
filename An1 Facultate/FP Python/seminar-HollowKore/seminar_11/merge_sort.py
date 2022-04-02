def best_case(n):
    return list(range(n))

def worst_case(n):
    """
    Worst case list of n elements
    """
    return best_case(n)[::-1]

def merge(arr, l, m, r):
    l1 = []
    l2 = []
    n1 = m-l+1
    n2 = r-m
    for i in range(n1):
        l1.append(arr[l+i])
    for j in range(n2):
        l2.append(arr[m+1+j])
    i = j = 0
    k = l
    while i < n1 and j < n2:
        if l1[i] < l2[j]:
            arr[k] = l1[i]
            i += 1
        else:
            arr[k] = l2[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = l1[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = l2[j]
        j += 1
        k += 1

def merge_sort(arr, l, r):
    if l >= r:
        return
    m = (l+r-1)//2
    merge_sort(arr, l, m)
    merge_sort(arr, m+1, r)
    merge(arr, l, m, r)

n = int(input())

arr = worst_case(n)

merge_sort(arr, 0, len(arr)-1)

print(arr)
