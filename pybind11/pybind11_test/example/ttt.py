from asyncore import read
import demo_pb2

R = 'read'
W = 'write'

def fwrb(filepath, opt, data=None):
    if opt == R:
        with open(filepath, 'rb') as f:
            return f.read()
    elif opt == W:
        with open(filepath, 'wb') as f:
            f.write(data)

filepath = './person_protobuf_data'
person = demo_pb2.Person()
person.name = "ayuliao"
person.id = 6
person.email = "xxx@xx.com"
person.phone = "13229483229"
person_protobuf_data = person.SerializeToString()
print(f'person_protobuf_data: {person_protobuf_data}')
fwrb(filepath, W, person_protobuf_data)


data_from_file = fwrb(filepath, R)
parse_person  = demo_pb2.Person()
# 没有数据
print(f'parse_person1 : {parse_person}')
# ParseFromString函数返回解析数据的长度
parse_data_len = parse_person.ParseFromString(data_from_file)
# 解析后，parse_person对象被填充了数据
print(f'parse_person2 : {parse_person}')
print(f'parse_data_len: {parse_data_len}')
print(f'data_from_file lenght: {len(data_from_file)}')