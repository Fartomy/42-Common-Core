def ft_water_reminder() -> None:
    d: int = int(input("Days since last watering: "))
    print("Water the plants!" if d > 2 else "Plants are fine")
