def ft_plant_age() -> None:
    age: int = int(input("Enter plant age in days: "))
    print("Plant is ready to harvest!" if age > 60
          else "Plant needs more time to grow.")
