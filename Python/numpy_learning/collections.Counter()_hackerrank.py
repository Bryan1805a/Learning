# ABC is a shoe shop owner. His shop has X number of shoes.
# He has a list containing the size of each shoe he has in his shop.
# There are N number of customers who are willing to pay x amount of money only if they get the shoe of their desired size.
# Your task is to compute how much money ABC earned.

# The first line contains X, the number of shoes.
# The second line contains the space separated list of all the shoe sizes in the shop.
# The third line contains N, the number of customers.
# The next N lines contain the space separated values of the shoe_sizes desired by the customer and x, the price of the shoe.

X = int(input())
shoe_sizes = list(map(int, input().split()))
N = int(input())
money = 0

for i in range(N):
    order = list(map(int, input().split()))
    if order[0] in shoe_sizes:
        money += order[1]
        shoe_sizes.remove(order[0])

print(money)