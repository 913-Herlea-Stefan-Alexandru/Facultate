
def create_set(set_list, n):
    for i in range(n):
        set_list.append('a'+str(i+1))

def create_used_dict(set_list, used_dict):
    for i in set_list:
        used_dict[i] = 0

def get_value(used_dict, item):
    return used_dict[item]

def set_value(used_dict, item, new_value):
    used_dict[item] = new_value

def to_str(set_list):
    set_str = '{'
    for i in set_list:
        if type(i) is list:
            set_str += to_str(i) + ', '
        else:
            set_str += i + ', '
    set_str += '\b\b}'
    return set_str

def comb(n, k):
    if k == 0 or n == k:
        return 1
    return comb(n-1, k) + comb(n-1, k-1)

'''
================================================================================
'''

def number_of_partitions(n):
    '''
    Calculates the number of partitions of a set with Bell's triangle
    :param n: Number of elements in the list (integer)
    :return: The number of partitions of the set with the given number of elements (integer)
    '''
    if n == 1:
        return 1
    list1 = [1]
    list2 = [1]
    p = 1
    while p < n:
        for i in range(p):
            list2.append(list1[i]+list2[i])
        list1 = list2.copy()
        list2.clear()
        list2.append(list1[-1])
        p += 1
    return list1[-1]

def sub_seq(n, k, used_dict, set_list, temp_list, subset_list):
    if k > 0:
        i = 0
        while len(set_list) - (k+i) >= 0:
            if get_value(used_dict, set_list[i]) == 0:
                temp_list.append(set_list[i])
                set_value(used_dict, set_list[i], 1)
                sub_seq(n, k-1, used_dict, set_list[i+1:], temp_list, subset_list)
                set_value(used_dict, set_list[i], 0)
                temp_list.pop()
            i += 1
    else:
        subset_list.append(temp_list.copy())

def partitions(set_list, used_dict, n, k, new_part, subset_list, history_set):
    if k > 0:
        p = k
        while p >= 1:
            sub_seq(n, p, used_dict, set_list, [], subset_list)
            for subset in subset_list:
                for item in subset:
                    set_value(used_dict, item, 1)
                new_part.append(subset)
                partitions(set_list, used_dict, n, k-p, new_part, subset_list[len(subset_list)+1:], history_set)
                new_part.pop()
                for item in subset:
                    set_value(used_dict, item, 0)
            subset_list.clear()
            p -= 1
    else:
        temp_set = set()
        for item in new_part:
            temp_tuple = tuple(item)
            temp_set.add(temp_tuple)
        if temp_set not in history_set:
            temp_set = frozenset(temp_set)
            print(to_str(new_part))
            history_set.add(temp_set)

'''
================================================================================
'''

def start():
    n = int(input("Read an integer from [1,8]: "))
    set_list = []
    create_set(set_list, n)
    used_dict = {}
    create_used_dict(set_list, used_dict)
    print('The set is: A = '+to_str(set_list))
    part = number_of_partitions(n)
    print('The number of partitions of the given set is: ' + str(part))
    history_set = set()
    partitions(set_list, used_dict, n, n, [], [], history_set)

start()