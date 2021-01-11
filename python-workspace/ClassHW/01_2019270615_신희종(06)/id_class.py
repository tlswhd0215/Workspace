class UserId:
    __id_set = [3, 6, 10, 5, 2]
    __id_num = 0

    def __init__(self):
        self.__id = UserId.__id_set[UserId.__id_num]
        self.__count = self.__id + 1
        UserId.__id_num += 1

    def get_id(self):
        return self.__id

    def get_count(self):
        return self.__count

list_user = []
for i in range(5):
    list_user.append(UserId())

for i in range(5):
    if list_user[i].get_id() % 2 == 0:
        print(list_user[i].get_count())
