"""
Domain file includes code for entity management
entity = number, transaction, expense etc.
"""

def create_score(p1, p2, p3):
    '''
    Creates a dictionary with all of the scores of a student
    :param p1: int problem one score
    :param p2: int problem two score
    :param p3: int problem three score
    :return: dict {'P1': problem one score, 'P2': problem two score, 'P3': problem three score}
    '''
    return {'P1': p1, 'P2': p2, 'P3': p3}

def get_p1(score):
    return score['P1']

def get_p2(score):
    return score['P2']

def get_p3(score):
    return score['P3']

def set_p1(score, new_score):
    score['P1'] = new_score

def set_p2(score, new_score):
    score['P2'] = new_score

def set_p3(score, new_score):
    score['P3'] = new_score

