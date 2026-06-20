def ft_count_harvest_iterative() -> None:
    i: int = int(input("Days until harvest: "))
    if i < 1:
        return
    for x in range(1, i + 1, 1):
        print("Day", x)
    print("Harvest time!")
