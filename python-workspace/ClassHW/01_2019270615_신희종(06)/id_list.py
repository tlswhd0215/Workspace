list_id = [[], []]
id_set = [3, 6, 10, 5, 2]
for i in range(5):
    list_id[0].append(id_set[i])
    list_id[1].append(list_id[0][i] + 1)
for i in range(5):
    if list_id[0][i] % 2 == 0:
        print(list_id[1][i])
