import calendar

def print_calendar(year, month):
    
    cal = calendar.month(year,month)
    print(f"Calendar for {calendar.month_name[month]} {year}:\n")
    print(cal)

def main():
    
    try:

        year = int(input("Enter the year: "))
        month = int(input("Enter the month: "))

        if 1 <= month <= 12:
            print_calendar(year,month)

        else:
            print("Invalid input. Please enter a month between 1 and 12")
    
    except ValueError:
        print("Invalid input. Please enter a numeric number")

if __name__ == "__main__":
    main()