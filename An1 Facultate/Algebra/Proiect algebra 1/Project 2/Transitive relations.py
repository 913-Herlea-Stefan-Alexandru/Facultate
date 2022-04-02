def create_set(set_list, n):
    for i in range(n):
        set_list.append('a'+str(i+1))

def create_used_dict(set_list, used_dict):
    for i in set_list:
        used_dict[to_str(i)] = 0

def get_value(used_dict, item):
    return used_dict[to_str(item)]

def set_value(used_dict, item, new_value):
    used_dict[to_str(item)] = new_value

def to_str(set_list):
    '''
    Used to print a list of elements in a readable manner
    :param set_list: the list of elements
    :return: -
    '''
    set_str = '('
    for i in set_list:
        if type(i) is list:
            set_str += to_str(i) + ', '
        else:
            set_str += i + ', '
    set_str = set_str[:-2]+')'
    return set_str

'''
=======================================================================================================================
'''

def sub_seq(n, k, set_list, temp_list, subset_list):
    '''
    Calculates all the possible two term combinations of the elements of the set
    :param n: (int) length of the set
    :param k: (int) used to keep count of the elements in the current subsequence
    :param set_list: (list) the list of elements in the set
    :param temp_list: (list) temporary list of the current subsequence
    :param subset_list: (list) the list of all of the possible two term combinations of the elements of the set
    :return: -
    '''
    if k > 0:
        i = 0
        while n - i > 0:
            temp_list.append(set_list[i])
            sub_seq(n, k-1, set_list, temp_list, subset_list)
            temp_list.pop()
            i += 1
    else:
        subset_list.append(temp_list.copy())

def cond(new_trans):
    '''
    Checks if the current relation is transitive or not
    :param new_trans: (list) a relation
    :return: None if the relation is transitive or a list of one of the needed elements for the relation to be transitive
    '''
    for subset1 in new_trans:
        for subset2 in new_trans:
            if subset1 == subset2:
                continue
            if subset1[1] == subset2[0]:
                temp_list = []
                temp_list.append(subset1[0])
                temp_list.append(subset2[1])
                if temp_list not in new_trans:
                    return temp_list
    return None

def transitive(subset_list, new_trans, used_dict):
    '''
    Creates and prints every transitive relation of the current set
    :param subset_list: (list) the list of all of the possible two term combinations of the elements of the set
    :param new_trans: (list) a new created relation which will be checked if it is transitive
    :param used_dict: (dictionary) a dictionary used to know if the current subset has already been added to the relation
    :return: -
    Prints a relation if it is transitive
    '''
    req = cond(new_trans)
    global index
    if req is None:
        str_new_trans = list(to_str(new_trans))
        str_new_trans[-1] = '}'
        str_new_trans[0] = '{'
        f = open("example1_write.txt", "a")
        f.write('R'+str(index)+' = '+"".join(str_new_trans)+'\n')
        f.close()
        #print('R'+str(index)+' = '+"".join(str_new_trans))
        index += 1
        for i in range(len(subset_list)):
            if get_value(used_dict, subset_list[i]) == 0:
                new_trans.append(subset_list[i])
                set_value(used_dict, subset_list[i], 1)
                transitive(subset_list[i:], new_trans, used_dict)
                new_trans.pop()
                set_value(used_dict, subset_list[i], 0)
    else:
        if req in subset_list:
            new_trans.append(req)
            set_value(used_dict, req, 1)
            transitive(subset_list, new_trans, used_dict)
            new_trans.pop()
            set_value(used_dict, req, 0)

'''
=======================================================================================================================
'''

def start():
    '''
    Handles user input and the functions used to print the transitive relations and how many they are
    :return: -
    '''
    #n = int(input("Read an integer from [1,8]: "))         #The commented lines of code are for console input and output
    f = open("example1_read.txt", "r")
    n = int(f.read(1))
    f.close()
    set_list = []
    create_set(set_list, n)
    str_new_trans = list(to_str(set_list))
    str_new_trans[-1] = '}'
    str_new_trans[0] = '{'
    f = open("example1_write.txt", "w")
    f.write('The set is: A = '+"".join(str_new_trans)+'\n')
    f.close()
    #print('The set is: A = '+to_str(set_list))
    subset_list = []
    sub_seq(n, 2, set_list, [], subset_list)
    used_dict = {}
    global index
    relations = 1
    index = 1
    create_used_dict(subset_list, used_dict)
    f = open("example1_write.txt", "a")
    f.write('\nThe transitive relations on the given set are: \n')
    f.write('\nR'+str(index)+' = Empty set\n')
    f.close()
    #print('R'+str(index)+' = Empty set')
    relations += 1
    index += 1
    for i in range(len(subset_list)):
        set_value(used_dict, subset_list[i], 1)
        transitive(subset_list[i:], [subset_list[i]], used_dict)
        set_value(used_dict, subset_list[i], 0)
    f = open("example1_write.txt", "a")
    f.write("\nThe number of transitive functions the given set has is: " + str(index-1))
    #print("The number of transitive functions the given set has is: " + str(index-1))
    f.close()

start()