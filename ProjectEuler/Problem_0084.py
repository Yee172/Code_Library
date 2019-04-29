# There is a game, Monopoly, described in:
#    https://projecteuler.net/problem=84
# If, instead of using two 6-sided dice, two 4-sided
# dice are used, find the six-digit modal string.
# ----------------------------------------------------
# Analysis: simulation
#           PS: to ensure the accuracy, I set a big number
#               for test time, user should be patient

from collections import defaultdict
from random import sample, shuffle

TEST_TIME = 10 ** 2

mapping = {'GO':    0,
           'A1':    1,
           'CC1':   2,
           'A2':    3,
           'T1':    4,
           'R1':    5,
           'B1':    6,
           'CH1':   7,
           'B2':    8,
           'B3':    9,
           'JAIL': 10,
           'C1':   11,
           'U1':   12,
           'C2':   13,
           'C3':   14,
           'R2':   15,
           'D1':   16,
           'CC2':  17,
           'D2':   18,
           'D3':   19,
           'FP':   20,
           'E1':   21,
           'CH2':  22,
           'E2':   23,
           'E3':   24,
           'R3':   25,
           'F1':   26,
           'F2':   27,
           'U2':   28,
           'F3':   29,
           'G2J':  30,
           'G1':   31,
           'G2':   32,
           'CC3':  33,
           'G3':   34,
           'R4':   35,
           'CH3':  36,
           'H1':   37,
           'T2':   38,
           'H2':   39}

map_length = len(mapping)
mapping_reverse = [''] * map_length
for x in mapping:
    mapping_reverse[mapping[x]] = x

dice = [1, 2, 3, 4]
number_of_dice = 2

def roll_a_dice():
    return sample(dice, 1)[0]


class Game:
    @staticmethod
    def stay_put(n):
        return n

    @staticmethod
    def go(n):
        return mapping['GO']

    @staticmethod
    def jail(n=0):
        return mapping['JAIL']

    @staticmethod
    def c1(n):
        return mapping['C1']

    @staticmethod
    def e3(n):
        return mapping['E3']

    @staticmethod
    def h2(n):
        return mapping['H2']

    @staticmethod
    def r1(n):
        return mapping['R1']

    @staticmethod
    def next_r(n):
        now = mapping_reverse[n]
        if now == 'CH1':
            return mapping['R2']
        if now == 'CH2':
            return mapping['R3']
        if now == 'CH3':
            return mapping['R1']

    @staticmethod
    def next_u(n):
        now = mapping_reverse[n]
        if now in ['CH1', 'CH3']:
            return mapping['U1']
        if now == 'CH2':
            return mapping['U2']

    @staticmethod
    def back3(n):
        return (n - 3) % map_length

    def __init__(self):
        self.player_place = mapping['GO']
        self.CC = [Game.go, Game.jail]\
                + [Game.stay_put] * 14
        shuffle(self.CC)
        self.CC_index = 0
        self.CH = [Game.go, Game.jail,
                   Game.c1, Game.e3,
                   Game.h2, Game.r1,
                   Game.next_r, Game.next_r,
                   Game.next_u, Game.back3]\
                + [Game.stay_put] * 6
        shuffle(self.CH)
        self.CH_index = 0
        self.consecutive_double = 0
        self.probability = [0] * map_length

    def move_one_step(self):
        point = [roll_a_dice() for _ in range(number_of_dice)]
        if len(set(point)) > 1:
            self.consecutive_double = 0
        else:
            self.consecutive_double += 1
        if self.consecutive_double == 3:
            self.player_place = Game.jail()
            self.consecutive_double = 0
            self.probability[self.player_place] += 1
            return

        step = sum(point)
        next_place = (self.player_place + step) % map_length
        next_place_name = mapping_reverse[next_place]
        if 'G2J' == next_place_name:
            self.player_place = Game.jail()
        elif 'CC' in next_place_name:
            self.player_place = self.CC[self.CC_index](next_place)
            self.CC_index += 1
            self.CC_index %= len(self.CC)
        elif 'CH' in next_place_name:
            self.player_place = self.CH[self.CH_index](next_place)
            self.CH_index += 1
            self.CH_index %= len(self.CH)
        else:
            self.player_place = next_place
        self.probability[self.player_place] += 1

    def simulation(self, step=10 ** 6):
        for _ in range(step):
            self.move_one_step()


probability = [0] * map_length
for _ in range(TEST_TIME):
    print('simulation', _)
    monopoly = Game()
    monopoly.simulation()
    for i, x in enumerate(monopoly.probability):
        probability[i] += x

print(''.join(map(lambda i: '%02d' % i, sorted(range(map_length), key=lambda i: probability[i], reverse=True)[:3])))
