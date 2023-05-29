max_need = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]
resources = [10, 5, 7]
allocated = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]
need = [[max_need[i][j] - allocated[i][j] for j in range(3)] for i in range(5)]
finished = [False] * 5
available = [resources[j] - sum([allocated[i][j]
                                for i in range(5)]) for j in range(3)]
safe_sequence = []
while False in finished:
    can_run = False
    for i in range(5):
        if not finished[i] and all([need[i][j] <= available[j] for j in range(3)]):
            can_run = True
            safe_sequence.append(i)
            available = [available[j] + allocated[i][j] for j in range(3)]
            finished[i] = True
            break
    if not can_run:
        print("System is in an unsafe state!")
        break

if len(safe_sequence) == 5:
    print("Safe sequence:", safe_sequence)
