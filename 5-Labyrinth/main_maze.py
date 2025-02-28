# -*- coding: utf-8 -*-
from maze import Maze
from collections import deque

def solve_maze(maze: Maze):
    start = maze.get_init_pos_player()
    stack = deque()
    visited = set()
    
    stack.append(start)
    
    while stack:
        current = stack.pop()
        
        if maze.find_prize(current):
            print("Prêmio encontrado em:", current)
            return True
        
        if current in visited:
            continue
        
        visited.add(current)
        maze.mov_player(current)
        
        x, y = current
        neighbors = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        
        for neighbor in neighbors:
            if neighbor not in visited and maze.is_free(neighbor):
                stack.append(neighbor)
    
    print("Prêmio não encontrado")
    return False

s = deque()

maze_csv_path = "labirinto1.txt"  # Substitua pelo caminho correto
maze = Maze()
maze.load_from_csv(maze_csv_path)
maze.init_player()
solve_maze(maze)
maze.run()