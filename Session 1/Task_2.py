import math

def compute_circle_area():
    try:    
        radius= float(input("Enter the radius: "))

        area = math.pi * math.pow(radius, 2)

        return area
    except ValueError:
        print(f" Invalid inout")

def main():

    area = compute_circle_area()
    print(f"Area of the circle: {area: .2f}")

if __name__ == "__main__":
    main()