from sys import stdin
from math import *
rl = lambda l: tuple(map(int, l.split()))
rd = lambda: rl(input())
class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __add__(self, pt):
        return Point(self.x + pt.x, self.y + pt.y)
    def __iadd__(self, pt):
        return self + pt
    def __mul__(self, n):
        return Point(self.x * n, self.y * n)
    def __imul__(self, n):
        return self * n
    def __truediv__(self, n):
        return Point(self.x / n, self.y / n)
    def __itruediv__(self, n):
        return self / n
    def __str__(self):
        return '%f %f' % (self.x, self.y)
    def distance(self, pt):
        return sqrt((self.x - pt.x) ** 2 + (self.y - pt.y) ** 2)
    def angle(self, pt):
        det_x = pt.x - self.x
        det_y = pt.y - self.y
        if det_x == 0:
            if det_y > 0:
                return pi / 2
            if det_y < 0:
                return pi / 2 * 3
            if det_y == 0:
                raise Exception('Fail to find angle between two identical points.')
        if det_x > 0:
            return atan(det_y / det_x)
        if det_x < 0:
            return atan(det_y / det_x) + pi
    def get_pt_by_dis_ang(self, dis, ang):
        return Point(self.x + cos(ang) * dis, self.y + sin(ang) * dis)
class Convex_polygon():
    def __init__(self):
        self.points = []
        self.core = None
        self.dis = None
        self.base_ang = 0
        self.ang = None
        self.pin = [0, 1]
    def add(self, pt):
        self.points.append(pt)
    def update(self):
        self.update_core()
        self.update_dis()
        self.update_ang()
    def cal_core_of_triangle(self, i, j, k):
        s = (self.points[j].x - self.points[i].x) * (self.points[k].y - self.points[i].y)
        s -= (self.points[j].y - self.points[i].y) * (self.points[k].x - self.points[i].x)
        return s, (self.points[i] + self.points[j] + self.points[k]) / 3 * s
    def update_core(self):
        self.core = Point(0, 0)
        s = 0
        for i in range(2, len(P.points)):
            det_s, det_core = self.cal_core_of_triangle(0, i, i - 1)
            self.core += det_core
            s += det_s
        self.core /= s
    def update_dis(self):
        self.dis = []
        for pt in self.points:
            self.dis.append(self.core.distance(pt))
    def update_ang(self):
        self.ang = []
        for pt in self.points:
            self.ang.append(self.core.angle(pt))
    def get_pt(self, i):
        return self.core.get_pt_by_dis_ang(self.dis[i], self.base_ang + self.ang[i])
    def __str__(self):
        return '\n'.join(('points: ' + '[' + ', '.join(str(pt) for pt in self.points) + ']',
                          'core: ' + str(self.core),
                          'dis: ' + str(self.dis),
                          'base_ang ' + str(self.base_ang),
                          'ang ' + str(self.ang),
                          'pin ' + str(self.pin)))
n, q = rd()
P = Convex_polygon()
for _ in range(n):
    P.add(Point(*rd()))
P.update()
for _ in stdin.readlines():
    s = rl(_)
    if s[0] == 1:
        __, f, t = s
        f -= 1
        t -= 1
        P.pin.remove(f)
        i = P.pin[0]
        top_pt = P.get_pt(i)
        P.core = Point(top_pt.x, top_pt.y - P.dis[i])
        P.base_ang = pi / 2 - P.ang[i]
        P.pin.append(t)
    else:
        __, v = s
        v -= 1
        print(P.get_pt(v))
