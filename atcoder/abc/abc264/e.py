
class UnionFind:
  
    def __init__(self):
        self.parents = {}

    def find(self, x):
        if x not in self.parents:
            self.parents[x] = x
            return x
        elif self.parents[x] == x:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x != y:
            self.parents[x] = y