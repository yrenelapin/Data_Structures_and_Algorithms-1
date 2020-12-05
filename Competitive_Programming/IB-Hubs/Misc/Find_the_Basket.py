N = int(input())
a = [0]*N

for i in range(N):
    temp = [int(x) for x in input().split()]
    a[i] = temp

# print(a)

# for ind in range(len(a)):

    
# Importing 
from itertools import cycle 
  
# list initialization 
List = a
  
# Defining no of iterations 
n = N
  
# Defining no of grouping 
k = N+1

possible_indices = []

for index, *ans in zip(range(n), *[cycle(List)] * k): 
    # printing ans 
    # print(type(ans),index) 
    carrots = 0
    possible = 1
    for each_list in ans[:N+1]:
        carrots = carrots + each_list[0]
        if ( carrots >= each_list[1] ):
            carrots =  carrots - each_list[1]
        else :
            possible  = 0
            break
    
    if (possible) :
        possible_indices.append(index) 


if (len(possible_indices) == 0):
    print(-1)
    exit

else :
    print(possible_indices[0])
