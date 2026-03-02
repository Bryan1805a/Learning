from collections import OrderedDict

N = int(input())
item_list = OrderedDict()

for _ in range(N):
    data = input().rsplit(' ', 1)
    item_name = data[0]
    price = int(data[1])
    
    item_list[item_name] = item_list.get(item_name, 0) + price
    
for item, net_price in item_list.items():
    print(f"{item} {net_price}")