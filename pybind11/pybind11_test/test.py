import example
# import proto.demo_pb2

print("==========")

print(example.add(2, 2))

class CC(example.BB):
    def a1(self):
        return "CC a1"
    # def a2(self):
    #     return "CC a2"
    def b1(self):
        return "CC b1"
    # def b2(self):
    #     return "CC b2"

cc=CC()
print(cc.a1())
print(cc.a2())
print(cc.b1())
print(cc.b2())