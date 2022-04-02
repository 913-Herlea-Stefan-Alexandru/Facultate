"""
What's wrong with the Lecture 3 calculator ?
    - No way to couple get_num, get_den with the rational number data type
        + same observation for calculator data type
    - Using dict or list prevents you from controlling access to the number
        e.g. q[1] = 0 -> just set denominator to 0 and you can't do anything about it
    - No way to use Python inbuilts (e.g str(), len(), +, *, ** ...)
    - How do I initialize my type the way Python intends to?
        my_data = [1,2,3], my_dict = {1:2}
"""