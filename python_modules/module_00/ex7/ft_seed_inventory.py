def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    match unit:
        case "packets":
            print(seed_type[0].upper() + seed_type[1:], "seeds:", quantity,
                  "packets avaiable")
        case "grams":
            print(seed_type[0].upper() + seed_type[1:], "seeds:", quantity,
                  "grams total")
        case "area":
            print(seed_type[0].upper() + seed_type[1:], "seeds: covers",
                  quantity, "square meters")
        case _:
            print("Unknown unit type")
