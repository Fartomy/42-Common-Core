def ft_count_harvest_recursive(cnt: int = 0, i: int = 1) -> None:
    if cnt == 0:
        cnt = int(input("Days until harvest: "))
    if cnt < 1:
        return
    if i < cnt + 1:
        print("Day", i)
        ft_count_harvest_recursive(cnt, i + 1)
    else:
        print("Harvest time!")
