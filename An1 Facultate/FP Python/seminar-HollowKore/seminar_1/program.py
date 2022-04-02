
def stringSplosion(word):
    result = ''

    for index in range(1, len(word)+1):
        #slice starts at 0, ends at index
        result += word[0:index]
        #print(word[0:index]) #when indexing, right value is excluded

    return result

print(stringSplosion('Code'))