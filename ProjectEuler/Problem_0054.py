# How many hands in file does Player 1 win?
# ----------------------------------------------------
# Analysis: brute force

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p054_poker.txt'
with open(PROBLEM_FILE, 'r') as f:
    hands = f.read().strip().split('\n')


class Card:
    value_mapping = dict({'2' : 2, '3' : 3, '4' : 4, '5' : 5, '6' : 6, '7' : 7, '8' : 8,
                          '9' : 9, 'T' : 10, 'J' : 11, 'Q' : 12, 'K' : 13, 'A' : 14})
    inverse_value_mapping = ['', '', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
                             'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace']
    plural_inverse_value_mapping = ['', '', 'Twos', 'Threes', 'Fours', 'Fives', 'Sixes', 'Sevens',
                                    'Eights', 'Nines', 'Tens', 'Jacks', 'Queens', 'Kings', 'Aces']
    suit_mapping = dict({'D' : 'Diamond', 'C' : 'Club', 'H' : 'Heart', 'S' : 'Spade'})
    def __init__(self, card):
        self.value = Card.value_mapping[card[0]]
        self.suit = card[1]

    def __eq__(self, another):
        return self.value == another.value

    def __lt__(self, another):
        return self.value < another.value

    def __gt__(self, another):
        return self.value > another.value

    def __str__(self):
        return 'value: %d, suit: %s' % (self.value, self.suit)


class Hand:
    def __init__(self, cards):
        self.cards = sorted(map(Card, cards))
        self.type = self.get_type()

    def get_type(self):
        is_consecutive = True
        is_same_suit = True
        for i in range(4):
            is_consecutive &= self.cards[i].value + 1 == self.cards[i + 1].value
            is_same_suit &= self.cards[i].suit == self.cards[i + 1].suit
        if is_consecutive and is_same_suit:
            if self.cards[4].value == 14:
                return [9, self.cards[4].value, [], 'Royal Flush']
            return [8, self.cards[4].value, [],
                    '%s-high Straight Flush' % Card.inverse_value_mapping[self.cards[4].value]]
        hand = []
        now = [self.cards[0]]
        for i in range(1, 5):
            if self.cards[i] == now[0]:
                now.append(self.cards[i])
            else:
                hand.append(now)
                now = [self.cards[i]]
        hand.append(now)
        hand.sort(key=len)
        character = list(map(len, hand))
        if character[-1] == 4:
            return [7, hand[1][0].value, [card for card in self.cards if not card == hand[1][0]],
                    'Four of a Kind with %s' % Card.plural_inverse_value_mapping[hand[1][0].value]]
        if character[0] == 2 and character[1] == 3:
            return [6, hand[1][0].value, [card for card in self.cards if not card == hand[1][0]],
                    'Full House with three %s' % Card.plural_inverse_value_mapping[hand[1][0].value]]
        if is_same_suit:
            return [5, self.cards[4].value, [card for card in self.cards if not card == self.cards[4]
                    or not card.suit == self.cards[4].suit], 'Flush with %ss' % Card.suit_mapping[self.cards[4].suit]]
        if is_consecutive:
            return [4, self.cards[4].value, [], '%s-high Straight' % Card.inverse_value_mapping[self.cards[4].value]]
        if character[-1] == 3:
            return [3, hand[-1][0].value, [card for card in self.cards if not card == hand[-1][0]],
                    'Three of %s' % Card.plural_inverse_value_mapping[hand[-1][0].value]]
        if character[-1] == 2 and character[-2] == 2:
            if hand[-1][0].value > hand[-2][0].value:
                maximum_value = hand[-1][0].value
                second_maximum_value = hand[-2][0].value
            else:
                maximum_value = hand[-2][0].value
                second_maximum_value = hand[-1][0].value
            return [2, maximum_value, [card for card in self.cards if not card.value == maximum_value],
                    'Pair of %s and Pair of %s' % (Card.plural_inverse_value_mapping[maximum_value],
                                                   Card.plural_inverse_value_mapping[second_maximum_value])]
        if character[-1] == 2:
            return [1, hand[-1][0].value, [card for card in self.cards if not card == hand[-1][0]],
                    'Pair of %s' % Card.plural_inverse_value_mapping[hand[-1][0].value]]
        return [0, self.cards[4].value, self.cards[:4], 'Highest card %s' % Card.inverse_value_mapping[self.cards[4].value]]
    
    def __gt__(self, another):
        if self.type[0] == another.type[0]:
            if self.type[1] == another.type[1]:
                for i in range(len(self.type[2]) - 1, -1, -1):
                    if self.type[2][i] == another.type[2][i]:
                        continue
                    return self.type[2][i] > another.type[2][i]
            return self.type[1] > another.type[1]
        return self.type[0] > another.type[0]

    def __str__(self):
        return '{' + self.type[-1] + ', [' + '; '.join(map(str, self.cards)) + ']' + '}'


res = 0
for each_round in hands:
    h = each_round.split()
    res += Hand(h[:5]) > Hand(h[5:])

print(res)
