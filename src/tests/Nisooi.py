import socket
import random

port = int(input())

def gen_grid():
    grid = []
    width = random.randint(5, 101)
    height = random.randint(5, 101)
    for i in range(height):
        row = []
        for j in range(width):
            row.append(1 + random.random() * 9)
        grid.append(row)
    return grid

def send_grid(socket, grid):
    s.recv(1024)
    toSend = (str(len(grid)) + ',' + str(len(grid[0]))).encode() + b'\n'
    for row in grid:
        string = ''
        for i in row:
            string += ',' + str(i)
        toSend += string[1:].encode() + b'\n'
    toSend += b'0,0' + b'\n'
    toSend += (str(len(grid) - 1) + ',' + str(len(grid[0]) - 1)).encode() + b'\n\n'
    s.sendall(toSend)
    return s.recv(1024)

BFS_results = []
DFS_results = []
BestFS_results = []
AStar_results = []

def refresh_socket(s):
    s.close()
    result = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result.connect(('127.0.0.1', port))
    return result

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', port))
for i in range(50):
    grid = gen_grid()
    s.sendall(b'solve find-graph-path BFS\n\n')
    result = send_grid(s, grid).decode().split('\n')[-1].split(',')
    BFS_results.append([result[0], len(result) - 2, len(grid) * len(grid[0])])
    s = refresh_socket(s)

    s.sendall(b'solve find-graph-path DFS\n\n')
    result = send_grid(s, grid).decode().split('\n')[-1].split(',')
    DFS_results.append([result[0], len(result) - 2, len(grid) * len(grid[0])])
    s = refresh_socket(s)

    s.sendall(b'solve find-graph-path BestFS\n\n')
    result = send_grid(s, grid).decode().split('\n')[-1].split(',')
    BestFS_results.append([result[0], len(result) - 2, len(grid) * len(grid[0])])
    s = refresh_socket(s)

    s.sendall(b'solve find-graph-path A*\n\n')
    result = send_grid(s, grid).decode().split('\n')[-1].split(',')
    AStar_results.append([result[0], len(result) - 2, len(grid) * len(grid[0])])
    if i == 49:
        s.close()
        break
    else:
        s = refresh_socket(s)

print("BFS:\n")
for pair in BFS_results:
    print(str(int(pair[0])) + "," + str(int(pair[1])) + "," + str(pair[2]))

print("DFS:\n")
for pair in DFS_results:
    print(str(int(pair[0])) + "," + str(int(pair[1])) + "," + str(pair[2]))

print("A*:\n")
for pair in AStar_results:
    print(str(int(pair[0])) + "," + str(int(pair[1])) + "," + str(pair[2]))

print("BestFS*:\n")
for pair in BestFS_results:
    print(str(int(pair[0])) + "," + str(int(pair[1])) + "," + str(pair[2]))
