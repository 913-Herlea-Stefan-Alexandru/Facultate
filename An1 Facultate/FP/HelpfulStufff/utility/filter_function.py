def filter(array, function):
    good_list = []
    for item in array:
        if function(item):
            good_list.append(item)
    return good_list